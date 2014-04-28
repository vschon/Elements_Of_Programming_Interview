#include <iostream>
#include <string>

using namespace std;


int translation(char c) {
    switch(c) {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return 0;
    }
}

int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if ( ( i > 0) && (translation(s[i]) > translation(s[i-1])))
            result += (translation(s[i]) - 2 * translation(s[i-1]));
        else
            result += translation(s[i]);
    }
    return result;
}

int main(int argc, char* argv[]) {
    
    if (argc > 1) {
        cout << romanToInt(string(argv[1])) << endl;
    }
    

    return 0;

}

