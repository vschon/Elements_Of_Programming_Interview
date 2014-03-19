#include "stdafx.h"

//Detailed implementation of stack supporting max in o(1) is in "stack.h"
int main() {
    Stack<int> S;
    S.push(3);
    S.push(2);
    S.push(4);
    S.push(1);
    cout << S.max() << endl;
    S.pop();
    cout << S.max() << endl;
    S.pop();
    cout << S.max() << endl;


    return 0;
}
