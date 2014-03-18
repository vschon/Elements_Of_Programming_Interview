#include "stdafx.h"

using namespace std;

bool isMatch(char prev, char end) {
    switch(prev) {
        case '(':
            return end == ')';
        case '[':
            return end == ']';
        case '{':
            return end == '}';
    }
}

bool ParathesesChecker(string input) {
    Stack<char> paratheses;
    bool result = true;
    for(auto ch : input) {
        if (ch == '(' || ch == '[' || ch == '{') {
            paratheses.push(ch);
            cout << "push " << ch << "into stack\n";
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            char pair = paratheses.pop();
            cout << "pop " << pair << "out of stack\n";
            if (!isMatch(pair, ch)) {
                result = false;
                break;
            }
            else continue;
        }
    }
    
    cout << "stack empty? " << paratheses.isEmpty() << endl;
    result = result && paratheses.isEmpty();
    return result;
}

int main() {

    string input = "{[2 *  (1 + 3)]";
    cout << ParathesesChecker(input) << endl;
    return 0;

}
