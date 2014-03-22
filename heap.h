#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

template<typename T>
class Heap {
public:
    Heap() {};
    Heap(vector<T>& unsortedArray);
    ~Heap(){}

    void insert(const T& info_);
    T peek() {
        if(!isEmpty())
            return heapArray[0];
    }
    T pop();
    bool isEmpty() {return getSize() == 0;}
    size_t getSize() {return heapArray.size();}
    void display() {
        for(typename std::vector<T>::iterator it = heapArray.begin(); it != heapArray.end(); it++)
            std::cout << *it << "  ";
    } 
    void reheapTopDown(vector<T>& unsortedArray);
    void reheapBottomUp(vector<T>& unsortedArray);


protected:
    void moveUp(size_t nodeIndex);
    void moveDown(size_t nodeIndex);
    size_t parent(size_t nodeIndex) {return (nodeIndex - 1)/2;}
    size_t leftChild(size_t nodeIndex) {return (2 * nodeIndex + 1);}
    size_t rightChild(size_t nodeIndex) {return (2 * nodeIndex + 2);}
protected:
    std::vector<T> heapArray;
};


template<typename T>
void Heap<T>::moveUp(size_t nodeIndex) {
    size_t parentIndex = parent(nodeIndex);
    while(nodeIndex > 0 && heapArray[nodeIndex] > heapArray[parentIndex]){
        swap<T>(heapArray[nodeIndex], heapArray[parentIndex]);
        nodeIndex = parentIndex;
        parentIndex = parent(nodeIndex);
    }
}

template<typename T>
void Heap<T>::moveDown(size_t nodeIndex) {
    size_t leftIndex = leftChild(nodeIndex);
    size_t rightIndex = rightChild(nodeIndex);
    size_t largestChildIndex = leftIndex;

    while(largestChildIndex < heapArray.size()) {
        //while the node has at least one child
        if (rightIndex < heapArray.size() && heapArray[leftIndex] < heapArray[rightIndex]) {
            //if the node has two children and the right child is larger than left child
            //then set largest child index to be the right, else left
            largestChildIndex = rightIndex;
        }

        if (heapArray[nodeIndex] < heapArray[largestChildIndex]) {
            //if the node is smaller than its largest child
            //then swap the node and its largest child(movedown)
            //continue to check the node with its new children
            //else, the node is in correct position, stop move down
            swap<T>(heapArray[nodeIndex], heapArray[largestChildIndex]);
            nodeIndex = largestChildIndex;
            leftIndex = leftChild(nodeIndex);
            rightIndex = rightChild(nodeIndex);
        }
        else break;
    }
    
}

template<typename T>
void Heap<T>::insert(const T& info_) {
    heapArray.push_back(info_);
    size_t location = heapArray.size() - 1;
    moveUp(location);
}

template<typename T>
T Heap<T>::pop() {
    
    swap<T>(heapArray.front(), heapArray.back());
    T temp = heapArray.back();
    heapArray.pop_back();
    moveDown(0);
    return temp;
}

template<typename T>
void Heap<T>::reheapTopDown(vector<T>& unsortedArray) {
    heapArray.clear();
    for(typename vector<T>::iterator it = unsortedArray.begin(); it != unsortedArray.end(); it++)
        insert(*it);
}

template<typename T>
void Heap<T>::reheapBottomUp(vector<T>& unsortedArray) {
    heapArray.clear();
    heapArray = unsortedArray;
    
    int lastNonLeafIndex = heapArray.size() / 2 - 1; 
    
    while(lastNonLeafIndex >= 0) {
        moveDown(lastNonLeafIndex);
        lastNonLeafIndex--;
    }
}

#endif
