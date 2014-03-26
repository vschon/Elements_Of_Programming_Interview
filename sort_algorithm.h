#include <vector>
#include "heap.h"
#include <algorithm>
#include <iostream>
#include <queue>

template<typename T>
void printArray(std::vector<T> &S) {
    for(auto num : S) {
        cout << num << "  ";
    }
    cout << endl;
}

template<typename T>
void InsertionSort(std::vector<T>& S) {
    for(size_t n = 1, j; n < S.size(); n++) {
        T temp = S[n];
        for(j = n; j > 0 && S[j-1] > temp; j--) {
            S[j] = S[j-1];
        }
        S[j] = temp;
    } 
}

template<typename T>
void SelectionSort(std::vector<T>& S) {

    int least = 0;
    for(int i = 0; i < S.size() - 1; i++) {
        least = i;
        for(int j = (i+1); j < S.size(); j++) {
            if(S[least] > S[j]) {
                least = j;
            }
        }
        swap<T>(S[i], S[least]);
    }
}

template<typename T>
void BubbleSort(std::vector<T>& S) {
    for(int i = 0; i < S.size() - 1; i++) {
        for(int j = 0; j < S.size() - 1 - i; j++) {
            if(S[j] > S[j+1])
                swap<T>(S[j], S[j+1]);
        }
    }
}

template<typename T>
void CombSort(std::vector<T>& S) {
    //Preprocess
    int step = int(S.size()/1.3);
    int j, k;

    while(step > 1) {
        for(j = S.size() - 1; j >= step; j--) {
            k = j - step;
            if (S[k] > S[j])
                swap<T>(S[k], S[j]);
        }
        step  = int(step/1.3);
    }

    //bubble sort
    bool again = true;
    for(int i = 0; i < S.size() -1 && again == true; i++) {
        again = false;
        for(int l = 0; (l < S.size() - 1 - i); l++) {
            if(S[l] > S[l+1]){
                again = true;
                swap<T>(S[l], S[l+1]);
            }
        }
    }
}

void CountSort(vector<long>& S) {
    //only suiable for positive integers, no template

    //find max of S
    long max = 0;
    for(auto item : S)
        max = item > max ? item : max;

    //create temp and count vector
    vector<long> temp(S.size(),0);
    vector<long> count((max+1), 0);
    
    //count frequency
    for(auto num : S)
        count[num]++;

    //Calculate cumulative count
    for(size_t i = 1; i < count.size(); i++)
        count[i] = count[i-1] + count[i];

    //insert elements into temp based on cumulative count
    size_t position = 0;
    for(auto num : S) {
        position = count[num] - 1;
        temp[position] = num;
        count[num]--;
    }

    S = temp;
}
        
    
template<typename T>
void QuickSort(vector<T>& S) {
    //Preprocess
    if(S.size() < 2) {
        return;
    }
    //Move the largest element to the last
    size_t maxIndex = 0;
    for(size_t i = 0; i < S.size(); i++) {
        maxIndex = S[maxIndex] < S[i] ? i : maxIndex;
    }

    swap<T>(S[maxIndex], S.back());


    //
}
        
template<typename T>
void QuickSort(vector<T>& S, int first, int last){

    int lower = first + 1;
    int upper = last;

    //the index of pivot = (first + last / 2)
    //put the pivot to the first place of the array;
    
    swap<T>(S[first] + S[(first + last)/2]);
    T pivot = S[first];

    //begin iteration
    while(lower <= upper) {
        //move lower index from left to right until it meets an element larger than pivot
        //move upper index from right to left until it meets an element smaller than pivor

        while(pivot > S[lower])
            lower++;
        while(pivot < S[upper])
            upper--;
        //swap the position of elements that are out of order
        if(lower < upper) {
            swap<T>(S[lower], S[upper]);
            lower++;
            upper--;
        }
    }
} 

template<typename T>
void ShellSort(vector<T>& S) {
    vector<int> increment(20, 0);
    int hCount;// index of the h
    int h;
    //fill in the increment array
    for(hCount = 0, h = 1; h < S.size(); hCount++) {
        increment[hCount] = h;
        h = 3*h + 1;
    } 
    
    //the increment array is not full, should remember the last index as hCount 

    hCount--;
    int subArray;//the beginning index of subArray: 0, 1, ..., h-1
    for(; hCount >=0; hCount--) {
        //begin from the largest step
        h = increment[hCount];
        //divided the array into h subarrays in place
        //sort each subarray respectively
        for(subArray = h; subArray < 2 * h; subArray++) {
            for(int j = h; j < S.size(); j = j + h) {
                T temp = S[j];
                int k = j;
                while((k - h >= 0) && S[k-h] > temp) {
                    S[k] = S[k-h];
                    k = k - h;
                }
                S[k] = temp;
            }
        }
    }
}

template<typename T>
void MoveDown(vector<T>& S, int end, int nodeIndex) { 
    /*
    psudo code
    
    while the node has leaf:
        find the largest child of the node
        if the node is smaller than the largest child
            swap the value of node and largest 
            set the node pointing to the largest child
    */

    int left = 2 * nodeIndex + 1;
    int right = 2 * nodeIndex + 2;
    int largestIndex = left;

    while(left < end) {
        if(right < end && S[right] > S[left])
            largestIndex = right;
        if(S[largestIndex] > S[nodeIndex]) {
            swap<T>(S[largestIndex], S[nodeIndex]);
            nodeIndex = largestIndex;
            left = 2 * nodeIndex + 1;
            right = 2 * nodeIndex + 2;
            largestIndex = left;
        }
        else break;
    }

}

template<typename T>
void HeapSort(vector<T>& S) {
    //reheap the array
    //start from the last non-leaf node, and move down the node if it is 
    //smaller than its descendants.
    for(int i = S.size()/2 - 1; i >=0; i--) {
        MoveDown<T>(S, S.size(), i);
    }
    
    swap<T>(S[0], S[S.size() - 1]);

    //Swap the first(max) and the last
    //MoveDown(first) for vector[0:n-2], and continue this step 
    for(size_t i = S.size() - 2;i > 0; i--) {
        MoveDown(S, i, 0);
        swap<T>(S[0], S[i]);
    }
}

template<typename T>
void Merge(vector<T>&S, int begin, int cut, int end) {
    //merge the S[begin] to S[end-1](inclusive) 
    vector<T> temp((end - begin), 0);
    int index1 = begin;
    int index2 = cut; 
    int tempIndex = 0;

    while(index1 < cut && index2 < end) {
        //while there are elements remaining in the two subarray
        if(S[index1] <= S[index2])
            temp[tempIndex++] = S[index1++];
        else
            temp[tempIndex++] = S[index2++];
    }


    if(index1 < cut) {
        while(index1 < cut)
            temp[tempIndex++] = S[index1++];
    }
    else if(index2 < end) {
        while(index2 < end)
            temp[tempIndex++] = S[index2++];
    }

    int index = begin;
    for(auto num : temp) {
        S[index] = num;
        index++;
    }

}
            
template<typename T>
void MergeSortRecursion(vector<T>& S, int begin, int end) {
    if((end - begin) >= 2) {
        int cut = (begin + end) / 2;
        MergeSortRecursion(S, begin, cut); //sort begin to mid+1 
        MergeSortRecursion(S, cut, end); //sort mid+1 to end
        Merge(S, begin, cut, end);
    }
}


template<typename T>
void MergeSortRecursion(vector<T>& S) {
    MergeSortRecursion(S, 0, S.size());
}

void RadixSort(vector<int>& S) {
    /*
    find the largest number max in the array
    digit: number of digits of max
    radix = 10
    factor = 1
    array of queues from 0 - 9
    for d = 1:digit
        for num in S:
            i = d_th digit of num
            put the number into queue_i
        for j = 0:9
            dequeue all elements of queue_i to temparray
    */

    //find the max of S
    int max(0);
    for(size_t i  = 0; i < S.size(); i++) {
        max = max < S[i]? S[i] : max;
    }
    int digits = 1;
    while(max != 0) {
        max = max%10;
        digits++;
    }
    
    int radix = 10;
    int factor = 1;
    vector<queue<int> > q;    
    for(int l = 0; l < radix; l++) {
        q.push_back(queue<int>());
    }

    int temp = 0;
    for(int d = 1; d <= digits; d++) {
        for(auto num : S) {
            temp = num / factor;
            temp = temp%radix;
            q[temp].push(num);
        }
        factor = factor * radix;
        
        int index = 0;
        for(int k = 0; k < radix; k++) {
            while (!q[k].empty()) {
                S[index] = q[k].front();
                q[k].pop();
                index++;
            }
        }
    }
}


