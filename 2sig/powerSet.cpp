#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


void powerSet(vector<int> A) {
    int n = A.size();
    
    if (n == 0) 
        return;

    for (int i = 0; i < pow(2, n); i++) {
        int j = i;
        int count = 0;
        while (j) {
            if ((j & 1) == 1)
                cout << A[count] << " ";
            count++;
            j = j >> 1;
        }
        cout << endl;
    }
}

int main() {
    vector<int> A = {1, 2, 3};
    powerSet(A);


    return 0;
}
