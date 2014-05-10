#include <iostream>

using namespace std;

/*
x&~(x-1) sets the lowest bit 1 to 1 and other bits to 0
Eg 1: last bit is 1
    x =         0000 0011
    x-1 =       0000 0010
    ~(x-1) =    1111 1101
    x&~(x-1) =  0000 0001

Eg 2: last bit is 0
    x =         0000 0010
    x-1 =       0000 0001
    ~(x-1) =    1111 1110
    x&~(x-1) =  0000 0010

suppose the index of lowest bit set of x is i(begin from right most), then
bit 1 to i - 1 are all zero and i is 1. Then:
x - 1 will set bit 1 to i - 1 to 1 and bit i to 0. And bit i + 1 to n will 
remain the same.

Eg:
x =         0000 0100
x - 1 =     0000 0011
                  ---

x =         0000 0110
x - 1 =     0000 0101
                   --

x =         0000 1100
x - 1 =     0000 1011
                  ---

Therefore, after we get x&~(x-1), only the lowest bit set i will remain 1 and 
all other bits are set to 0. 
*/

int computeParity(unsigned long x){
    
    
    int count = 0;
    unsigned long y = 0;
    while(x) {
        y = ~(x&~(x-1));
        x &= y;
        count ++;
    }
        
    return count%2;
}

int main() {
    
    //test case 1:
    unsigned long x = 0;
    cout << "x = " << x << " " << " parity = " << computeParity(x) << endl;
 
    //test case 2:
    x = 1;
    cout << "x = " << x << " " << " parity = " << computeParity(x) << endl;
    
    //test case 3:
    x = 3;
    cout << "x = " << x << " " << " parity = " << computeParity(x) << endl;
 
    return 0;
}

