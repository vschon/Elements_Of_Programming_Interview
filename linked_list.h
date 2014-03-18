#ifndef LINKED_LIST_H
#define LINKED_LIST_H


//Node
template<typename T> 
class Node {
public:
    Node();
    Node(T data_, Node* ptr_);
public:
    T data;
    Node* next;
};


template<typename T>
class LinkedList {
public:
    LinkedList(){
        head = tail = 0;
    }
    
    ~LinkedList();
    
    bool isEmpty() {
        return head == 0;
    }
    
    void addToHead(T data_);
    void addToTail(T data_);
    
    T deleteFromHead();
    T deleteFromTail();
    
    void deleteNode(T info);
    bool isInList(T info) const;
    void display();
public:
    Node<T>* head;
    Node<T>* tail;
};


#endif
