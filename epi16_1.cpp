#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>


using namespace std;

typedef enum {UNVISITED, VISITED, BLOCKED} Status;

class Coordinate {
public:
    int x;
    int y;
    Status status;
    char symbol;
public:
    Coordinate() {
        status = UNVISITED;
        symbol = 'O';
    };
    Coordinate(int x_, int y_) : x(x_), y(y_), status(UNVISITED), symbol('O')  {}
};

class Maze {
public:
    int dimension;
    vector<vector<Coordinate> > board;
    int entryX, entryY;
    int exitX, exitY;
    Coordinate exit;
    stack<pair<int, int> > path;
    
public:
    Maze(int mazeSize) {
        dimension = mazeSize;
        board.resize(dimension);
        for (int i = 0; i < mazeSize; i++) {
            for (int j = 0; j < dimension; j++) {
                board[i].push_back(Coordinate(i, j));
            }
        }
    }
    void setBlock(int ,int );
    void setEntry(int, int);
    void setExit(int, int);
    void display();
    bool isLegal(int ,int ,int, int);
    void searchPath();
    bool DFS(int x, int y);
};


void Maze::setEntry(int x_, int y_) {
    entryX = x_;
    entryY = y_;
    board[x_][y_].symbol = 'A';
}

void Maze::setExit(int x_, int y_) {
    exitX = x_;
    exitY = y_;
    board[x_][y_].symbol = 'B';
}

void Maze::setBlock(int x_, int y_) {
    board[x_][y_].status = BLOCKED;
    board[x_][y_].symbol = 'X';
}

bool Maze::isLegal(int x1, int y1, int x2, int y2) {
    
    if (x1 < 0 || y1 < 0 || x1 >= dimension || y1 >= dimension || 
        x2 < 0 || y2 < 0 || x2 >= dimension || y2 >= dimension)
        return false;
    if (x1 == x2 && y1 == y2) 
        return false;
    if (abs(x1 - x2) > 1 || abs(y1 - y2) > 1)
        return false;
    if (board[x2][y2].status == BLOCKED)
        return false;
    return true;
}

void Maze::display() {
    cout << endl;
    for (int row = dimension - 1; row >= 0; row--) {
        for (int col = 0; col < dimension; col++) {
            cout << board[row][col].symbol << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Maze::searchPath() {
    cout << "size " << path.size() << endl;
    if (DFS(entryX, entryY)) {
        cout << "Successful!" << endl;
        cout << "The path is: " << endl;
        while(!path.empty()) {
            pair<int, int> temp = path.top();
            path.pop();
            cout << temp.first << " " << temp.second << endl;
        }
    }
    
}

bool Maze::DFS(int x, int y) {
    //cout << "Visiting " << x << " " << y << endl;
    if (x == exitX && y == exitY) {
        path.push(pair<int,int>(x,y));
        return true;
    }

    bool result;

    board[x][y].status = VISITED;
    vector<pair<int, int> > legalMove;

    for(int up = -1; up <= 1; up++) {
        for (int right = -1; right <= 1; right++) {
            int step = abs(up) + abs(right);
            if (step == 1 && isLegal(x, y, x + up, y + right)) {
                legalMove.push_back(pair<int ,int>(x+up,y+right));
            }
        }
    }
    for (auto move : legalMove) {
        if (board[move.first][move.second].status == UNVISITED)
            if (DFS(move.first, move.second)){
                path.push(pair<int, int>(x,y));
                return true;
            }
    }
    return false; 
}


int main() {

    //Construct maze
    Maze M(4);
    M.setEntry(0,0);
    M.setExit(3,3);
    M.setBlock(0,1);
    M.setBlock(1,1);
    //M.setBlock(2,1);
    //M.setBlock(3,1);
    M.setBlock(3,0);
    M.setBlock(3,2);
    
    M.display();

    M.searchPath();

    return 0;
}
