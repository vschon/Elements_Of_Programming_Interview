#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int rodCut_Normal(vector<int>& S, int n) {
    if (n == 0) {
        return 0;
    }
    
    int max = -100;

    for (int i = 1; i <= n; i++) {
        int temp = S[i] + rodCut_Normal(S, n-i);
        max = temp > max ? temp : max; 
    }
    return max;
}


int rodCut_MemoizedAux(vector<int>& S, vector<int>& result, int n) {

    int optimal = 0;
    if (result[n] >= 0)
        return result[n];
    else {
        if (n==0)
            optimal = 0;
        else {
             for (int i = 1; i <= n; i++) {
                int temp = S[i] + rodCut_MemoizedAux(S, result, n-i);
                optimal = temp > optimal ? temp : optimal; 
            }
        }
        result[n] = optimal;
        return optimal;
    }
}

int rodCut_Memoized(vector<int>& S, int n) {
    vector<int> result(n+1, -100);
    if (n == 0)
        return 0;
    else
        return rodCut_MemoizedAux(S, result, n);
}

int rodCut_BottomUp(vector<int>& S, int n) {

    if (n == 0)
        return 0;
    else {
        vector<int> result(n+1, - 100);
        vector<int> pArray(n+1, 0);
        result[0] = 0;
        for(int i = 1; i <= n; i++) {
            int max = -100;
            int maxIndex = -100;
            for (int j = 1; j <= i; j++) {
                int temp = S[j] + result[i-j];
                if (temp > max) {
                    max = temp;
                    maxIndex = j;
                }
            }
            result[i] = max;
            pArray[i] = maxIndex;
        }
   

    cout << "print pArray " << endl;
    for(int index : pArray) {
        cout << index << "  ";
    }
    cout << endl;

    //out put the optimal cut
    int m = n;
    cout << "Optimal cut is : " << endl;
    while(m > 0) {
        cout << pArray[m] << " ";
        m = m - pArray[m];
    }
    cout << endl;
    return result[n];
    }
}

int main() {
    srand(time(NULL));
    vector<int> price = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 10;
    for (int j = 11; j <= n; j++){
        int randomNum = rand() % 6 + 1;
        price.push_back(price.back() + randomNum);
    }
    //cout << "Traditional: " << rodCut_Normal(price, n) << endl;
    //cout << "Memoized: " << rodCut_Memoized(price, n) << endl;
    cout << "Bottom up: " << rodCut_BottomUp(price, n) << endl;

    return 0;
}
