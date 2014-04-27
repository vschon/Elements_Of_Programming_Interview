#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> maxSubarray(const vector<int>& A) {
    //pseudo code
    //calculate the cumulative sum array S, S[-1] = 0 
    //loop through S: 
    //      keep running minimum and minIndex
    //      for each S[i] in S, calculate S[i] - S[minimum];
    //      keep a running max of S[i] - S[minimum]
    //      keep the index of running max

    vector<int> S;
    S.push_back(0);//index: -1 : S[0]
    for (auto num : A) {
        S.push_back(num + S.back());
    }

    int min = S[0], minIndex = 0;
    int max = -1;
    int maxIndex;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] < min) {
            min = S[i];
            minIndex = i;
        }
        
        if (S[i] - min > max) {
            max = S[i] - min;
            maxIndex = i;
        }
    }

    return pair<int, int>(minIndex , maxIndex-1 );
    
}



int main() {
    vector<int> A = {904, 40, 523, 12, -335, -385, -124, 481, -31, 10000};
    pair<int, int> result = maxSubarray(A);

    cout << "from " << result.first << " to " << result.second << endl;


    return 0;
}
