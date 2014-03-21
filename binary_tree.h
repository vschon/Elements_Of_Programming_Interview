#ifndef BINARY_TREE_H
#define BINARY_TREE_H 

#include <stack>
#include <queue>

template<typename T>
class BSTNode {
public:
    BSTNode() {
        parent = 0;
        left = 0;
        right = 0;
    }
    BSTNode(T info_, BSTNode<T>* l = 0, BSTNode<T>* r = 0) {
        parent = 0;
        data = info_;
        right = r;
        left = l;
    }
        
public:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode<T>* parent;
};

template<typename T>
class BinaryTree {
public:
    BinaryTree() {
        root = 0;
    }

    BinaryTree(BSTNode<T>* root_) {
        root = root_;
    }
    ~BinaryTree() {
        clear();
    }
    void clear() {
        clear(root);
    }

    bool isEmpty() const{
        return root == 0;
    }
    T* search(const T& info_) const;

    void traverseBSF();

    void preOrderRecursion(BSTNode<T>* node);
    void preOrderRecursion() {
        preOrderRecursion(root);
    }

    void inOrderRecursion(BSTNode<T>* node);
    void inOrderRecursion() {
        inOrderRecursion(root);
    }

    void postOrderRecursion(BSTNode<T>* node);
    void postOrderRecursion() {
        postOrderRecursion(root);
    }

    void morrisInOrder();

    void insert(const T& info_);

    void deleteByMerge(BSTNode<T>*& node);
    void searchAndDeleteByMerge(const T& info_);
    void deleteByCopy(BSTNode<T>*& node);
    void searchAndDeleteByCopy(const T& info_);


protected:
    BSTNode<T>* root;
    T* search(BSTNode<T>* node, const T& info_) const;
    void visit(BSTNode<T>* p);
    void clear(BSTNode<T>* node) {
        if(node != 0) {
            if(node->left != 0)
                clear(node->left);
            if(node->right != 0) 
                clear(node->right);
            delete node;
            node = 0;
        }
    }
};
    




template<typename T>
T* BinaryTree<T>::search(const T& info_) const {
    return search(root, info_);
}

template<typename T>
T* BinaryTree<T>::search(BSTNode<T>* node, const T& info_) const {
    while(node != 0) {
        if (info_ == node->data) 
            return &node->data;
        else if(info_ > node->data) 
            node = node->right;
        else
            node = node->left;
    }
    return 0;
}

template<typename T>
void BinaryTree<T>::visit(BSTNode<T>* p) {
    cout << p->data << "  "; 
}

template<typename T>
void BinaryTree<T>::traverseBSF() {

    queue<BSTNode<T>*> Q; 
    BSTNode<T>* p = root;
    if (p != 0) {
        Q.push(p);
        while(!Q.empty()) {
            p = Q.front();
            Q.pop();
            visit(p);
            if (p->left != 0) { 
                Q.push(p->left);
            }

            if (p->right != 0) {
                Q.push(p->right);
            }
        }
    }
    cout << endl;
}
        
template<typename T>
void BinaryTree<T>::inOrderRecursion(BSTNode<T>* node) {
    if (node != 0) {
        inOrderRecursion(node->left);
        visit(node);
        inOrderRecursion(node->right);
    }
}

template<typename T>
void BinaryTree<T>::preOrderRecursion(BSTNode<T>* node) {
    if (node != 0) {
        visit(node);
        preOrderRecursion(node->left);
        preOrderRecursion(node->right);
    }
}

template<typename T>
void BinaryTree<T>::postOrderRecursion(BSTNode<T>* node) {
    if (node != 0) {
        postOrderRecursion(node->left);
        postOrderRecursion(node->right);
        visit(node);
    }
}

template<typename T>
void BinaryTree<T>::morrisInOrder() {
    //current is the current node
    BSTNode<T>* current = root;
    BSTNode<T>* temp;
    
    while (current != 0) {
        if (current->left == 0) {
            visit(current);
            current = current->right;
        }
        else {
        temp = current->left;
        //traverse to the rightmost node or a temporary parent
        while(temp->right != 0 && temp->right != current) 
            temp = temp->right;
            if (temp->right == 0) {
                //if it is the rightmost node
                //make current as the right child of the rightmost node 
                //introduce cycle and destroy the tree structure
                temp->right = current;
                //make the left node of the original root as the temp root
                current = current->left;
            }
            else {
                //if it is the current node
                //restore it to a tree
                visit(current);
                temp -> right = 0;
                current = current->right;
            }
        
        }
    }        
}

template<typename T>
void BinaryTree<T>::insert(const T& info_) {
    BSTNode<T>* current = root;
    BSTNode<T>* prev = 0; // Used to point to parent
    
    while(current != 0) {
        prev = current;
        if(info_ < current->data)
            current = current->left; 
        else current = current->right;
    }
    
    if(root == 0)
        root = new BSTNode<T>(info_);
    else if(info_ < prev->data)
        prev->left = new BSTNode<T>(info_);
    else prev->right = new BSTNode<T>(info_);
}

template<typename T>
void BinaryTree<T>::deleteByMerge(BSTNode<T>*& node) {
    BSTNode<T>* temp = node;
    if (node != 0) {
        if (node->right == 0 && node->left == 0)
            node = 0;
        else if (node->right == 0 && node->left != 0)
            node = node->left;
        else if (node->right != 0 && node->left == 0)
            node = node->right;
        else {
            // move to the predessor of node
            temp = temp->left;
            while(temp->right != 0)
                temp = temp->right;
            temp->right = node->right;
            temp = node;
            node = node->left;
        }
        delete temp;
    }
}

template<typename T>
void BinaryTree<T>::searchAndDeleteByMerge(const T& info_) {
    BSTNode<T>* node = root;
    BSTNode<T>* prev = 0;
    
    while(node != 0) {
        if(node->data == info_)
            break;
        prev = node;
        if(info_ < node->data)
            node = node->left;
        else
            node = node->right;
    }
    
    if(node != 0 && node->data == info_) {
        if(node == root) 
            deleteByMerge(root);
        else if(node == prev->left)
            deleteByMerge(prev->left);
        else if(node == prev->right)
            deleteByMerge(prev->right);
    }
    else if( root != 0)
        cout << "Cannot find the value " << endl;
    else
        cout << "Empty tree" << endl;
}

template<typename T>
void BinaryTree<T>::deleteByCopy(BSTNode<T>*& node){
    BSTNode<T>* prev;
    BSTNode<T>* temp = node;
    
    if(node->left == 0 && node->right == 0)
        node = 0;
    else if(node->left == 0 && node->right != 0)
        node = node->right;
    else if(node->left != 0 && node->right == 0)
        node = node->left;
    else {
        prev = node;
        temp = node->left;
        while(temp->right != 0) {
            prev = temp;
            temp = temp->right;
        }
        node->data = temp->data;
        if(prev == node)
            prev->left = temp->left;
        else
            prev->right = temp->left;
    }
    delete temp;
}


template<typename T>
void BinaryTree<T>::searchAndDeleteByCopy(const T& info_) {
    BSTNode<T>* node = root;
    BSTNode<T>* prev = 0;
    
    while(node != 0) {
        if(node->data == info_)
            break;
        prev = node;
        if(info_ < node->data)
            node = node->left;
        else
            node = node->right;
    }
    
    if(node != 0 && node->data == info_) {
        if(node == root) 
            deleteByCopy(root);
        else if(node == prev->left)
            deleteByCopy(prev->left);
        else if(node == prev->right)
            deleteByCopy(prev->right);
    }
    else if( root != 0)
        cout << "Cannot find the value " << endl;
    else
        cout << "Empty tree" << endl;
}


            



    

#endif
