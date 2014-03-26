#include "stdafx.h"
using namespace std;

template<typename T>
vector<T>* findIntersection(vector<T>& M, vector<T>& N){
    vector<T>* p = new vector<T>;

    for(int i = 0, j = 0; i < M.size() && j < N.size(); ){
        if(M[i] == N[j]){
            p->push_back(M[i]);
            i++;
            j++;
        }
        else if(M[i] < N[j])
            i++;
        else if(M[i] > N[j])
            j++;
    }
    return p;
}

int main() {
    vector<int> M = {1, 2, 3};
    vector<int> N = {3, 5, 6};

    vector<int>* p = findIntersection(M, N);
    for(auto num : *p) {
        cout << num << "  ";
    }
    cout << endl;
    return 0;
}
