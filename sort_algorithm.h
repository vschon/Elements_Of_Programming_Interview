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
        
    
