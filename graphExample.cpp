#include "stdafx.h"
using namespace std;

int main() {
    GraphMatrix<int, int> g;
    cout << "insert first vertex \n";
    g.insertVertex(1);
    g.insertVertex(2);
    cout << "Total vertices : " << g.vertexCount << endl;
    cout << "Edge between node 0 and 0? " << g.exists(0,0) << endl;
    cout << endl;
    cout << "Remove the 0_th node\n";
    g.removeVertex(0);
    cout << "Total vertices : " << g.vertexCount << endl;
    return 0;
}


