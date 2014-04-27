#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>


/*
FindMissingChar(string S)
    hashmap H<char, int)
    initialize H
    set every char count to 0
    
    for each char in s:
        increase the count for the char by 1

    for each <key,value> pair in H
        if value = 0
            print key
*/


using namespace std;

void findMissingChar(string& S) {
    unordered_map<char, int> H;
    int a = int('a');
    int A = int('A');

    for (int i = 0; i < 26; i++) {
        H.insert({{char(a + i), 0}, {char(A + i), 0}});
    }

    for (char c: S) {
        H[c] += 1;
    }

    for (auto h : H) {
        if (h.second == 0) {
            cout << h.first << "  ";
        }
    }
    cout << endl;
}

int main() {
    string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY!";
    findMissingChar(s);

    return 0;
}

