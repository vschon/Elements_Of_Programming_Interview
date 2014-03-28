#include "stdafx.h"
using namespace std;

int main() {
    GraphMatrix<string, int> g;
    cout << "insert vertices a - g \n";
    g.insertVertex("a");//0
    g.insertVertex("b");//1
    g.insertVertex("c");//2
    g.insertVertex("d");//3
    //g.insertVertex("e");//5
    //g.insertVertex("f");//6
    //g.insertVertex("g");//7
    //g.insertVertex("h");//8
    //g.insertVertex("i");//9


    //g.insertEdge(0, 0, 1, 1);// g.insertEdge(0, 1, 0, 1);
    g.insertEdge(0, 0, 2, 1);// g.insertEdge(0, 2, 0, 1);
    //g.insertEdge(0, 0, 3, 1);// g.insertEdge(0, 3, 0, 1);
    //g.insertEdge(0, 1, 2, 1);
    g.insertEdge(0, 2, 1, 1);
    g.insertEdge(0, 1, 3, 1);// g.insertEdge(0, 3, 1, 1);
    //g.insertEdge(0, 2, 3, 1);// g.insertEdge(0, 3, 2, 1);

    //DFS
    //cout << "Begin DFS " << endl;
    //g.depthFirstSearch();
    //cout << endl;

    cout << "Begin BFS " << endl;
    g.breadthFirstSearch();
    cout << endl;

    return 0;
}


