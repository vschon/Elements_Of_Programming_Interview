#include <queue>
#include <iostream>
using namespace std;

#define L -10000
#define U 10000

class Node {
public:
    Node(int data_ = 0, Node* right_ = 0, Node* left_ = 0) : data(data_), left(left), right(right) {}

public:
    int data;
    Node* left;
    Node* right;
};

bool checkBST(Node* node, int lowerBound, int upperBound) {
    if(node == 0)
        return true;
    cout << "check node data " << node->data << " L: " << lowerBound << " U: " << upperBound << endl;
    if(node->data < lowerBound)
        return false;
    if(node->data > upperBound)
        return false;

    return checkBST(node->left, lowerBound, node->data)\
           && checkBST(node->right, node->data, upperBound);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(9);

    cout << checkBST(root, L, U) << endl;

    return 0;

}
