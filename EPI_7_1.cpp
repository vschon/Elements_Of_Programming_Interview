
template<typename T>
void Solve_7_1<T>(Node<T>* L, Node<T>* F) {

    
    Node<int>* tempL = L.head;
    Node<int>* tempF = F.head;

    



int main() {

    string line;
    getline(cin, line);
    
    vector<string> data = split(line, ' ');
    vector<int> intData;
    
    for (vector<string>::iterator it = data.begin(); it != data.end(); it++) {
        string strTemp = *it;
        int temp = atoi(strTemp.c_str());
        intData.push_back(temp);
    }
    
    
    
 
    vector<int> L = {1,3,5,7,9};
    vector<int> F = {2,4,6,7,10};
   
    LinkedList<int> L;
    LinkedList<int> F;

    //fill in the linked list
    for (vector<int>::iterator it = intData.begin(); it != intData.end(); it++) {
        l.addToTail(*it);
    }
 
    cout << l.isInList(5) << endl;
    
}

 
