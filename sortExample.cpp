#include "stdafx.h"
using namespace std;

void print(vector<int> &S) {
    for(auto num : S) {
        cout << num << "  ";
    }
    cout << endl;
}

void print(vector<long> &S) {
    for(auto num : S) {
        cout << num << "  ";
    }
    cout << endl;
}

int main() {
    cout << "Original Array : ";
    vector<int> S = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print(S);
    
    cout << "Insertion Sort : ";
    InsertionSort<int>(S);
    print(S);
    

    cout << "Selection sort: " << endl;
    S = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print(S);
    SelectionSort<int>(S);
    print(S);

    cout << "Bubble sort: " << endl;
    S = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print(S);
    BubbleSort<int>(S);
    print(S);

    cout << "Comb sort: " << endl;
    S = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print(S);
    CombSort<int>(S);
    print(S);

    cout << "Count sort: " << endl;
    vector<long> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print(A);
    CountSort(A);
    print(A);

    cout << "Shell sort: " << endl;
    vector<int> M;
    for(size_t i = 0; i < 20; i++){
        M.push_back(20-i);
    }
    print(M);
    ShellSort<int>(M);
    print(M);

    cout << "Heap sort: " << endl;
    vector<int> B = {11,23,43,10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print(B);
    HeapSort<int>(B);
    print(B);

    cout << "Merge sort: " << endl;
    
    vector<int> C;
    for(size_t i = 0; i < 20; i++){
        C.push_back(20-i);
    }
    print(C);
    MergeSortRecursion<int>(C);
    print(C);

    cout << "Radix sort: " << endl;
    vector<int> D;
    for(size_t i = 0; i < 20; i++){
        D.push_back(20-i);
    }
    print(D);
    RadixSort(D);
    print(D);
   
   return 0;
}
