#include "stdafx.h"

using namespace std;

template<typename T>
void visit(BSTNode<T>*& node){
    if (node != 0)
        cout << node->data << "  ";
}

template<typename T>
void traverse(BSTNode<T>*& root) {
    BSTNode<T>* node = root;
    BSTNode<T>* prev = 0;

    while(node != 0) {
        
       if(prev == node->parent) {
            //prev==0 means program starts at root(parent of root is 0)
            prev = node;
            if(node->left != 0) {
                node = node->left;
            }
            else if (node->right != 0) {
                visit<T>(node);
                node = node->right;
            }
            else {
                // a leaf: visit it self and back to its parent
                visit<T>(node);
                node = node->parent;
            }
        }

        if(prev == node->left) {
            //just visited its left subtree
            visit<T>(node);
            prev = node;
            if(node->right != 0)
                node = node->right;
            else
                node = node->parent;
        }

        if(prev == node->right) {
            //just visited its right subtree
            //back to its parent
            prev = node;
            node = node->parent;
        }
    }

}

int main() {
 
    BinaryTree<int> tree;
    tree.insert(13);
    tree.insert(10);
    tree.insert(25);
    tree.insert(2);
    tree.insert(12);
    tree.insert(20);
    tree.insert(31);
    tree.insert(29);

    //tree.morrisInOrder();
    //cout << endl;
    
    BSTNode<int>* root = new BSTNode<int>(13);
    root->parent = 0;

    root->left = new BSTNode<int>(10);
    root->left->parent = root;

    root->right = new BSTNode<int>(25);
    root->right->parent = root;

    root->left->left = new BSTNode<int>(2);
    root->left->left->parent = root->left;

    root->left->right = new BSTNode<int>(12);
    root->left->right->parent = root->left;

    root->right->left = new BSTNode<int>(20);
    root->right->left->parent = root->right;

    root->right->right = new BSTNode<int>(31);
    root->right->right->parent = root->right;
    
    root->right->right->left = new BSTNode<int>(29);
    root->right->right->left->parent = root->right->right;
    
    BinaryTree<int> tree2(root);
    
    tree2.morrisInOrder();
    cout << endl;
    traverse<int>(root);
    cout << endl;

    //traverse<int>(root);

    return 0;
}
