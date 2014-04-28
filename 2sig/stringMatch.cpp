#include <string>
#include <iostream>

using namespace std;


bool baseClassMatch(string& test, string& pattern) {
    //cout << "test: " << test << endl;
    //cout << "pattern: " << pattern << endl;
    if (pattern == "*")
        return true;
    else if (test.size() != 1)
        return false;
    else {
        if (pattern == "?")
            return true;
        else if (pattern == test)
            return true;
        else
            return false;
    }
}

bool stringMatchHelper(string& test, string& pattern) {
    bool result = false;
    //base cases
    if (pattern.size() == 1) {
        result = baseClassMatch(test, pattern);
        return result;
    }

    if (pattern[0] == 'a' || pattern[0] == 'b') {
        if (test.size() > 0 && pattern[0] == test[0]) {
            string subPattern = pattern.substr(1);
            string subTest = test.substr(1);
            result = stringMatchHelper(subTest, subPattern);
        }
        else {
            result = false;
        }
    }

    if (pattern[0] == '?') {
        if (test.size() > 0) {
            string subPattern = pattern.substr(1);
            string subTest = test.substr(1);
            result = stringMatchHelper(subTest, subPattern);
        }
        else
            result = false;
    }

    if (pattern[0] == '*') {
        for (int i = 0; i < test.size(); i++) {
            string subPattern = pattern.substr(1);
            string subTest = test.substr(i);
            result = stringMatchHelper(subTest, subPattern);
            if (result == true)
                break;
        }
    }

    return result;
}


int main() {
    string test = "babababab";
    string pattern = "?abab*";
    
    cout << stringMatchHelper(test, pattern) << endl;

    return 0;

}
