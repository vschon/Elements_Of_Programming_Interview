#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void sortList(vector<string>& S) {

    vector<bool> states; //true: int false: str
    vector<int> intVec;
    vector<string> strVec;

    for (auto str : S) {
        try {
            int i = stoi(str);
            intVec.push_back(i);
            states.push_back(true);
        }
        catch (...){
            strVec.push_back(str);
            states.push_back(false);
        }
    }

    sort(intVec.begin(), intVec.end());
    sort(strVec.begin(), strVec.end());

    vector<int>::iterator iIter = intVec.begin();
    vector<string>::iterator strIter = strVec.begin();

    for (auto b : states) {
        if (b) {
            cout << *iIter << " ";
            iIter++;
        }
        else {
            cout  << *strIter << " ";
            strIter++;
        }
    }
}

int main() {

    vector<string> S = {"d", "4", "c", "3", "b", "2", "a", "1"};
    sortList(S);


    return 0;
}

