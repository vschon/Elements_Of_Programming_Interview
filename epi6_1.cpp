#include "stdafx.h"

using namespace std;


vector<int> SortArray(vector<int> A, size_t indicator) {
    int pivot = A[indicator];
    vector<int>::iterator small = A.begin();
    vector<int>::iterator equal = A.begin();
    vector<int>::iterator big = A.end() - 1;
    
    while(equal <= big) {
        if (*equal < pivot) {
            int temp = *small;
            *small = *equal;
            *equal = temp;

            equal++;
            small++;
        }
        else if(*equal == pivot) {
            equal++;
        }
        else {
            int temp = *equal;
            *equal = *big;
            *big = temp;
            big--;
        }
    }
    return A;
}

    
int main() {
    vector<int> A = {8, 8, 5, 2, 5, 2, 2, 5, 8, 5};
    size_t i = 4;
    
    vector<int> sortedA = SortArray(A, i);
        
    for(vector<int>::iterator it = sortedA.begin(); it != sortedA.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
    
    
