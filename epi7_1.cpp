#include "linked_list.h"
#include "utils.h"
#include "linked_list.cpp"

using namespace std;

template<typename T>
Node<T>* MergeSortedLinkedList(Node<T>* LHead, Node<T>* FHead) {
    Node<T>* Li = LHead;
    Node<T>* Fi = FHead;

    Node<T>* mergedHead = 0;
    Node<T>* mergedTail = 0;

    if (Li->data <= Fi->data) {
        mergedHead = Li;
        Li = Li->next;
    }
    else {
        mergedHead = Fi;
        Fi = Fi->next;
    }
    
    mergedTail = mergedHead;

    while (Li != 0 && Fi != 0) {
        if (Li->data <= Fi->data) {
            mergedTail->next = Li;
            mergedTail = mergedTail->next;
            Li = Li->next;
        }
        else {
            mergedTail->next = Fi;
            mergedTail = mergedTail->next;
            Fi = Fi->next;
        }
    }

    if (Li != 0) 
        mergedTail->next = Li;
    else if (Fi != 0) 
        mergedTail->next = Fi;

    return mergedHead;
}
    
        
int main() {
    LinkedList<int> L;
    for (int i = 1; i < 5; i += 2) {
        L.addToTail(i);
    }

    L.display();

    LinkedList<int> F;
    for (int i = 2; i < 6; i += 2) {
        F.addToTail(i);
    }
    F.display();
    
    Node<int>* Lhead =  L.head;
    Node<int>* Fhead =  F.head;
    Node<int>* result;

    result = MergeSortedLinkedList<int>(Lhead, Fhead); 

    Node<int>* temp = result;
    while(temp != 0) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
    return 0;

}
