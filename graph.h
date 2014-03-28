#include <vector>


typedef enum {UNVISITED, VISITED} VStatus; 
typedef enum {UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} EStatus;

template <typename Tv, typename Te>
class Graph {
private:
    void reset();
    void BFS(int, int&);
    void DFS(int, int&);
public:
    Graph() {}
    virtual ~Graph() {}
    Graph(int vertexCount_, int edgeCount_) : vertexCount(vertexCount_), edgeCount(edgeCount_) {}
    //vertex
    int vertexCount;
    //insert data into vertex
    virtual int insertVertex(Tv const& info_) = 0;
    //remove vertex 
    virtual Tv removeVertex(int vIndex) = 0;
    //return the reference to the data of vertex
    virtual Tv& vertex(int) = 0;
    //status of vertex
    virtual int inDegree(int vIndex) = 0;
    virtual int outDegree(int vIndex) = 0;
    virtual VStatus& status(int vIndex) = 0;

    //edge
    int edgeCount;
    virtual bool exists(int vIndex1, int vIndex2) = 0;
    virtual void insertEdge(Te const& edgeInfo_, int vIndex1, int vIndex2, double weight) = 0;
    virtual Te removeEdge(int vIndex1, int vIndex2) = 0;
    virtual EStatus& status(int vIndex1, int vIndex2) = 0;
    virtual Te& edge(int vIndex1, int vIndex2) = 0;
    virtual double& weight(int vIndex1, int vIndex2) = 0;

    //void BFS(int vIndex1);
    //void DFS(int vIndex2);
    //void prim(int vIndex)
    //void dijkstra(int)
};


template <typename Tv> class Vertex {
public:
    Tv data;
    int inDegree, outDegree;
    VStatus status;
public:
    Vertex(Tv const& data_) : data(data_), inDegree(0), outDegree(0), status(UNVISITED) {}
};

template <typename Te> class Edge {
public:
    Edge(Te const& data_, double weight_) : data(data_), weight(weight_), status(UNDETERMINED) {}
public:
    Te data;
    double weight;
    EStatus status;
};

//adjacency matrix implementation

template<typename Tv, typename Te>
class GraphMatrix: public Graph<Tv, Te> {

private:
    //set of vertices
    vector<Vertex<Tv> > V;
    //set of edges: matrix of pointers to edge object
    vector<vector<Edge<Te>*> > E;

public:
    GraphMatrix() : Graph<Tv,Te>(0,0) {}
    ~GraphMatrix() {
        for(int i = 0; i < this->vertexCount; i++) {
            for (int j = 0; j < this->vertexCount; j++) {
                if(E[i][j] != nullptr) {
                    delete E[i][j];
                }
            }
        }
    }

    //vertex operation
    virtual Tv& vertex(int vIndex) {return V[vIndex].data;}
    virtual int inDegree(int vIndex) {return V[vIndex].inDegree;}
    virtual int outDegree(int vIndex) {return V[vIndex].outDegree;}
    virtual VStatus& status(int vIndex) {return V[vIndex].status;}

    virtual int insertVertex(Tv const& data_) {
        //add a null pointer at the bottom of each row 
        for(int j = 0; j < this->vertexCount; j++) {
            E[j].push_back(0);
        }
        this->vertexCount++;
        //add a new row into E
        vector<Edge<Te>* > temp(this->vertexCount, nullptr);
        E.push_back(temp);
        //add a new point into V
        V.push_back(Vertex<Tv>(data_));
        return (this->vertexCount-1);
    }

    virtual Tv removeVertex(int i) {
        for(int j = 0; j < this->vertexCount; j++) {
            if(exists(i,j)) {
                delete E[i][j];
                E[i][j] = nullptr;
                V[j].inDegree--;
            }
        }
        E.erase(E.begin() + i);
       
        this->vertexCount--;
        for(int j = 0; j < this->vertexCount; j++) {
            if(exists(j,i)) {
                delete E[j][i];
                E[j][i] = nullptr;
                V[j].outDegree--;

            }
            E[j].erase(E[j].begin() + i);
        }
       
        Tv temp = vertex(i);
        V.erase(V.begin() + i);
        return temp;
    }

    //Edge 

    virtual bool exists(int vIndex1, int vIndex2) {
        return ((0 <= vIndex1 && vIndex1 < this->vertexCount) && (0 <= vIndex2 && vIndex2 < this->vertexCount) && E[vIndex1][vIndex2] != nullptr);
    }

    virtual EStatus& status(int vIndex1, int vIndex2) {return E[vIndex1][vIndex2]->status;}
    virtual Te& edge(int vIndex1, int vIndex2) {return E[vIndex1][vIndex2]->data;}
    virtual double& weight(int vIndex1, int vIndex2) {E[vIndex1][vIndex2]->weight;} 

    virtual void insertEdge(Te const& edgeInfo_, int vIndex1, int vIndex2, double weight_) {
        if(!exists(vIndex1, vIndex2)) {
            E[vIndex1][vIndex2] = new Edge<Te>(edgeInfo_, weight_);
            this->edgeCount++;
            V[vIndex1].outDegree++;
            V[vIndex2].inDegree++;
        }
    }

    virtual Te removeEdge(int vIndex1, int vIndex2) {
        Te temp = edge(vIndex1, vIndex2);
        delete E[vIndex1][vIndex2];
        E[vIndex1][vIndex2] = nullptr;
        this->edgeCount--;
        V[vIndex1].outDegree--;
        V[vIndex2].inDegree--;
        return temp;
    }

    //BFS
    virtual void depthFirstSearchByNode(int vIndex1) {
        cout << "Visting " << V[vIndex1].data << endl; 
        V[vIndex1].status = VISITED;
        for (int vIndex2 = 0; vIndex2 < V.size(); vIndex2++) {
            if (exists(vIndex1, vIndex2) && V[vIndex2].status != VISITED) {
                depthFirstSearchByNode(vIndex2); 
            }
        }
    }
    
    virtual void depthFirstSearch() {
        for (size_t i = 0; i < V.size(); i++) {
            if (V[i].status == UNVISITED) {
                depthFirstSearchByNode(i);
            }
        }
    }
    
    virtual void breadthFirstSearchByNode(int vIndex1) {
        queue<int> q;
        q.push(vIndex1);

        while (!q.empty()) {
            int index = q.front();
            q.pop();
            cout << "Visiting " << V[index].data << endl;
            V[index].status = VISITED;
            for (int vIndex2 = 0; vIndex2 < V.size(); vIndex2++) {
                if (exists(index, vIndex2) && V[vIndex2].status != VISITED) {
                    q.push(vIndex2);
                }
            }
        }
    }

    virtual void breadthFirstSearch() {
        for (size_t i = 0; i < V.size(); i++) {
            if (V[i].status == UNVISITED) {
                breadthFirstSearchByNode(i);
            }
        }
    }
};
