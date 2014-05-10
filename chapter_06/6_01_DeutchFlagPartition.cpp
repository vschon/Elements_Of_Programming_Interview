#include <vector>
#include <iostream>
#include <utility>

using namespace std;

vector<int> &flagPartition(vector<int> &A, int i) {

    if (i >= A.size())
        throw("Invalid index");

    int pivot = A[i];
    swap(A[0], A[i]);
    
    int si = 0; //points to the element after the small partition
    int li = A.size() - 1; //point to the element before the large partition
    int mi = 0; //moving index, iterate throught the array A

    while(mi < li) {
        if(A[mi+1] < pivot) {
            swap(A[mi+1], A[si]);
            si++;
            mi++;
        }
        else if (A[mi+1] > pivot) {
            swap(A[mi+1], A[li]);
            li--;
        }
        else {
            mi++;
        }
    }
    return A;
}

void printArray(vector<int>& A) {

    for (auto num : A) {
        cout << num << " ";
    }
    cout << endl;
}

void test(int test, vector<int>& A, int index) {
    cout << "Test  " << test << endl;
    cout << "Pivot index = " << index << " Array = :" << endl;
    printArray(A);
    cout << "Partitioned: " << endl;
    printArray(flagPartition(A, index));
    cout << endl;
}
int main() {

    //test 1
    int index = 2;
    vector<int> A = {1, 2, 3, 4, 5, 6};
    test(1, A, index);

    //test2 
    index = 0;
    A = {1, 2, 3, 4, 5, 6};
    test(2, A, index);

    //test3 
    index = 5;
    A = {1, 2, 3, 4, 5, 6};
    test(3, A, index);


    //test4 
    A = {6, 5, 4, 3, 2, 1};
    index = 0;
    test(4, A, index);
    
    //test5
    A = {6, 5, 4, 3, 2, 1};
    index = 5;
    test(5, A, index);

    //test6
    A = {1};
    index = 0;
    test(6, A, index);

    //test7
    A = {1};
    index = 1;
    try {
        test(7, A, index);
    }
    catch (...) {
        cout << "Exception " << endl;
    }

    //test8
    A = {};
    index = 1;
    try {
        test(8, A, index);
    }
    catch (...) {
        cout << "Exception " << endl;
        cout << endl;
    }

    return 0;
}
