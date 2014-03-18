#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "linked_list.h"
#include "utils.h"
using namespace std;

template<typename T>
Node<T>::Node() {
    next = 0;
}

template<typename T>
Node<T>::Node(T data_, Node* ptr_ = 0) {
    next = ptr_;
    data = data_;
}


//Linked list
template<typename T>
LinkedList<T>::~LinkedList() {
    for(Node<T>* p; !isEmpty();) {
        p = head->next;
        delete head;
        head = p;
    }
}

template<typename T>
void LinkedList<T>::addToHead(T info_) {
    head = new Node<T>(info_, head);
    if (tail == 0)
        tail = head;
}

template<typename T>
void LinkedList<T>::addToTail(T info_) {
    if (tail != 0) {
        tail->next = new Node<T>(info_);
        tail = tail->next;
    }
    else {
        head = tail = new Node<T>(info_);
    }
}

template<typename T>
T LinkedList<T>::deleteFromHead() {
    if (isEmpty())
        throw("Empty");
    T tempData = head->data;
    if (head == tail) {
        delete head;
        head = tail = 0;
    }
    else {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    return tempData;
}

template<typename T>
T LinkedList<T>::deleteFromTail() {
    if (isEmpty())
        throw("Empty");
    T tempData = tail->data;
    if (tail == head)
        head = tail = 0;
    else {
        Node<T>* temp;
        for(temp = head; temp != tail; temp = temp->next); 
        delete tail;
        tail = temp;
        tail->next = 0;
    }
    return tempData;
}

template<typename T>
void LinkedList<T>::deleteNode(T info_) {
    if (isEmpty())
        throw("Empty");
    if (head == tail && head->data = info_) {
        delete head;
        head = tail = 0;
    }
    else if (info_ == head->data)
        deleteFromHead();
    else {
        Node<T>* temp;
        Node<T>* prev;
        for(temp = head->next, prev = head; (temp != 0 && temp->data != info_); prev = temp, temp = temp->next)
        if (temp != 0) {
            if (temp == tail)
                deleteFromTail();
            else {
                prev->next = temp->next;
                delete temp;
            }
        }
    }
}


template<typename T>
bool LinkedList<T>::isInList(T info_) const {
    Node<T>* temp;
    for(temp = head; (temp != 0 && temp->data != info_); temp = temp->next);
    return temp != 0;
}

template<typename T>
void LinkedList<T>::display() {
    if (!isEmpty()) {
        Node<T>* temp;
        for(temp = head; temp != 0; temp = temp->next) {
            cout << temp->data << " ";
        }
    cout << endl;
    }
}
    
   
