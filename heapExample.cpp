#include "stdafx.h"
using namespace std;

int main() {

    Heap<int> h;
    cout << "The size of heap is : ";

    h.insert(10);
    h.insert(12);
    h.insert(3);
    h.insert(32);
    cout << h.getSize() << endl;
    h.display();
    cout << endl;

    int gg = h.pop();
    h.display();
    cout << endl;
    h.pop();
    h.display();
    cout << endl;
    return 0;

}
