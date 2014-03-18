#include <iostream>
using namespace std;

int CountOne(unsigned long l) {
    int count = 0;
    while(l) {
        count  += (l & 1);
        l = l >> 1;
    }
    return count;
}
        

int main() {
    cout << "Please enter a integer\n";
    unsigned long l;
    cin >> l;
    
    cout << "Number of 1 is : " << CountOne(l) << endl;
}

    
     
