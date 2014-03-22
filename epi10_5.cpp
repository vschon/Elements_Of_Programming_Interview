#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

template<typename T>
class MinHeap {
public:
    MinHeap() {}
    ~MinHeap(){}

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
void MinHeap<T>::moveUp(size_t nodeIndex) {
    size_t parentIndex = parent(nodeIndex);
    while(nodeIndex > 0 && heapArray[nodeIndex] < heapArray[parentIndex]){
        swap<T>(heapArray[nodeIndex], heapArray[parentIndex]);
        nodeIndex = parentIndex;
        parentIndex = parent(nodeIndex);
    }
}

template<typename T>
void MinHeap<T>::moveDown(size_t nodeIndex) {
    size_t leftIndex = leftChild(nodeIndex);
    size_t rightIndex = rightChild(nodeIndex);
    size_t smallestChildIndex = leftIndex;

    while(smallestChildIndex < heapArray.size()) {
        //while the node has at least one child
        if (rightIndex < heapArray.size() && heapArray[leftIndex] > heapArray[rightIndex]) {
            //if the node has two children and the right child is larger than left child
            //then set largest child index to be the right, else left
            smallestChildIndex = rightIndex;
        }

        if (heapArray[nodeIndex] > heapArray[smallestChildIndex]) {
            //if the node is smaller than its largest child
            //then swap the node and its largest child(movedown)
            //continue to check the node with its new children
            //else, the node is in correct position, stop move down
            swap<T>(heapArray[nodeIndex], heapArray[smallestChildIndex]);
            nodeIndex = smallestChildIndex;
            leftIndex = leftChild(nodeIndex);
            rightIndex = rightChild(nodeIndex);
        }
        else break;
    }
    
}

template<typename T>
void MinHeap<T>::insert(const T& info_) {
    heapArray.push_back(info_);
    size_t location = heapArray.size() - 1;
    moveUp(location);
}

template<typename T>
T MinHeap<T>::pop() {
    
    swap<T>(heapArray.front(), heapArray.back());
    T temp = heapArray.back();
    heapArray.pop_back();
    moveDown(0);
    return temp;
}

int main(){
    MinHeap<int> H;
    int k = 3;
    int num = 0;
    int count = 1;
    /*

    H.insert(6);
    H.insert(1);
    H.insert(2);
    H.insert(3);
    H.insert(4);
    H.display();
    cout << endl;
    H.pop();
    H.display();
    cout << endl;
    */
    while(cin >> num) {
        if (count <= k) {
            H.insert(num);
            H.display();
            cout << endl;
            cout << num << " " << H.peek() << endl;
        }
        else {
            if (num <= H.peek()) {
                cout << num << " " << H.peek() << endl;
            }
            else {
                H.pop();
                H.insert(num);
                H.display();
                cout << endl;
                cout << num << " " << H.peek() << endl;
            }
        }
        count++;
    }
}
