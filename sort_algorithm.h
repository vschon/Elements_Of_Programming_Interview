#include <vector>

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
    vector<int> increment;
    int hCount, h;
    //fill in the increment array
    for(hCount = 0, h = 1; h < S.size(); i++) {
        increment[hCount] = h;
        h = 3*h + 1;
    } 

    //the increment array is not full, should remember the last index as hCount 
    int subArray;
    for(hCount = increment.size() - 1; hCount >=0; hCount--) {
        //begin from the largest step
        h = h[i];
        subArray = h;

        //divided the array into h subarrays in place
        //sort each subarray respectively
        for(int j = h; j < S.size(); j = j + h) {
            T temp = h[j];
            while((j - h >= 0) && S[j] < temp) {
                S[j] = S[j-h];
            }
        }
    }
}
