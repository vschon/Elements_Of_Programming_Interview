#include "stdafx.h"



using namespace std;

bool checkLetter(const string& letter, const string& magazine) {

    HashTable h;
    //count char frequency of letter
    for(int i = 0; i < letter.size(); i ++) {
        string ch = letter.substr(i , 1);
        int count = 0;
        //try to access the ch key in dict
        try {
            count = h.at(ch);
        }
        catch(invalid_argument err) {
            //if not in dict, insert ch into dict
            h.insert(ch, 1);
            continue;
        }
        // if get count
        h.insert(ch, (count + 1));
    }
    cout << "The characters in the letter is:" << endl;
    h.display();
    cout << endl;

    for(int j = 0; j < magazine.size(); j ++) {
        string chM = magazine.substr(j, 1);
        int num = 0;
        try{
            num = h.at(chM);
            if((num - 1) > 0){
                h.insert(chM, (num -1));
            }
            else
                h.remove(chM);
        }
        catch(invalid_argument err) {
            continue;
        }
    }

    h.display();
    cout << endl;
    cout << h.size() << endl;

    return h.size() == 0;

}
    
int main() { 

    string letter = "Brandon";
    string magazine = "Brandon";

    bool success = checkLetter(letter, magazine);

    success == true ? cout << "success!"<< endl : cout << "failure!" << endl;
   
    
    return 0;
}


