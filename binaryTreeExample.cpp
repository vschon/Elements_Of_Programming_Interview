#include "stdafx.h"
using namespace std;

int main() {
    //Insert
    BinaryTree<int> tree;
    tree.insert(13);
    tree.insert(10);
    tree.insert(25);
    tree.insert(2);
    tree.insert(12);
    tree.insert(20);
    tree.insert(31);
    tree.insert(29);

    /* Search
    int* p = tree.search(100);
    p == 0 ? cout << "Not found! "<< endl : cout << *p << endl;
    */

    //*traverse
    tree.traverseBSF();
        
    /*In order traverse*/
    //tree.inOrderRecursion();
    
    /*Pre order traverse*/
    //tree.preOrderRecursion();

    /*Post order traverse*/
    //tree.postOrderRecursion();

    //Non recursive traverse
    //tree.morrisInOrder();

    //deleteByMerge
    tree.searchAndDeleteByMerge(25);
    tree.traverseBSF();
    
    //deleteByCopy
    tree.searchAndDeleteByCopy(13);
    tree.traverseBSF();
    

}
