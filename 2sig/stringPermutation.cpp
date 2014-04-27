#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;





void stlSolution(vector<int>& S) {
    sort(S.begin(), S.end());
    do {
        for (auto i : S) {
            cout << i << " ";
        }
        cout << endl;
    }while(next_permutation(S.begin(), S.end()));
    cout << endl;
}

void stringPermutationHelper(string& S, int i, vector<string>& result) {
    if (i == S.size() -1) {
        result.emplace_back(S);
        return;
    }

    for(int j = i; j < S.size(); j++) {
        swap(S[i], S[j]);
        stringPermutationHelper(S, i+1, result);
        swap(S[i], S[j]);
    }
}

vector<string> stringPermutation(string& S) {
    vector<string> result;
    stringPermutationHelper(S, 0, result);
    return result;
}



int main() {
    
    
    //stlSolution(a);

    string s = "aab";
    vector<string> result = stringPermutation(s);
    for (auto c : result) {
        cout << c << endl;
    }

    cout << endl;
    set<string> result2(result.begin(), result.end());
    for (auto c : result2) {
        cout << c << endl;
    }


    return 0;
}
