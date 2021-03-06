#include "stdafx.h"
using namespace std;

template <typename T>
int binarySearchLarger(const vector<T>& S, T k) {
    int L = 0;
    int U = S.size() - 1;
    int M = (L + U) / 2;
    int finalM = -1;

    while (L <= U){
        M = (L + U) / 2;
        if(S[M] <= k){
            L = M + 1;
        }
        else if(S[M] > k) {
            finalM = M;
            U = M - 1;
        }
    }
    return finalM;
}
        
    
int main() {

    vector<int> S = {-4, -2, 1, 3, 3, 9, 23, 54, 54, 60};
    int k = 60;
    cout << binarySearchLarger<int>(S, k) << endl;
    return 0;
}
    
