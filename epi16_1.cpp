#include <vector>
#include <queue>
#include  <iostream>
#include <cmath>


using namespace std;

typedef enum {UNVISITED, VISITED, BLOCKED, ENTRY, EXIT} Status;

class Coordinate {
public:
    int x;
    int y;
    Status status;
public:
    Coordinate() {
        status = UNVISITED;
    };
    Coordinate(int x_, int y_) : x(x_), y(y_), status(UNVISITED) {}
};

class Maze {
public:
    int dimension;
    vector<vector<Coordinate> > board;
    Coordinate entrance;
    Coordinate exit;
public:
    Maze(int mazeSize) {
        dimension = mazeSize;
        board.resize(dimension);
        for (int i = 0; i < mazeSize; i++) {
            board[i].resize(dimension);
            for (int j = 0; j < dimension; j++) {
                boardi[i].push_back(Coordinate())
        }
    }
    void setBlock(Coordinate block);
    void setEntrance(Coordinate entrance_);
    void setExit(Coordinate exit_);
    void display();
    bool checkNeighbor(Coordinate c1, Coordinate c2);
};


void Maze::setEntrance(Coordinate entrance_) {
    entrance.x = entrance_.x;
    entrance.y = entrance_.y;
    board[entrance.x][entrance.y] = 'A';
}

void Maze::setExit(Coordinate exit_) {
    exit.x = exit_.x;
    exit.y = exit_.y;
    board[exit.x][exit.y] = 'B';
}

void Maze::setBlock(Coordinate block_) {
    board[block_.x][block_.y] = 'X';
}

bool Maze::checkNeighbor(Coordinate c1, Coordinate c2) {
    if (c1.x < 0 && c1.y < 0 && c1.x >= dimension && c1.y >= dimension && 
        c2.x < 0 && c2.y < 0 && c2.x >= dimension && c2.y >= dimension)
        return false;
    if (c1.x == c2.x && c1.y == c2.y) 
        return false;
    if (abs(c1.x - c2.x) > 1 || abs(c1.y - c2.y) > 1)
        return false;
    if (board[c2.x][c2.y] == 'X')
        return false;
    return true;

}

void Maze::display() {
    cout << endl;
    for (int row = dimension - 1; row >= 0; row--) {
        for (int col = 0; col < dimension; col++) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



int main() {

    //Construct maze
    Maze M(4);
    M.setEntrance(Coordinate(0,0));
    M.setExit(Coordinate(3,3));
    M.setBlock(Coordinate(0,1));
    M.setBlock(Coordinate(1,1));
    M.setBlock(Coordinate(3,0));
    M.setBlock(Coordinate(3,2));
 
    M.display();
    return 0;
}
