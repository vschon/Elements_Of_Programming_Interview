#include <iostream>

using namespace std;
class chessBoard {
public:
    chessBoard();
    chessBoard(int n);
    void findSolutions();
private:
    const bool available;
    const int squares, norm;
    bool *column, *leftDiagonal, *rightDiagonal;
    int *positionInRow, howMany;
    void putQueen(int row);
    void printBoard();
    void initializeBoard();
};

chessBoard::chessBoard() : available(true), squares(8), norm(squares-1) {
    initializeBoard();
}

chessBoard::chessBoard(int n): available(true), squares(n), norm(squares-1) {
    initializeBoard();
} 

void chessBoard::initializeBoard() {
    column = new bool[squares];
    for(size_t i = 0; i < squares; i++) {
        column[i] = available;
    }
    leftDiagonal = new bool[2*squares - 1];
    rightDiagonal = new bool[2*squares - 1];
    for(size_t j = 0; j < (2 * squares - 1); j++) {
        leftDiagonal[j] = available;
        rightDiagonal[j] = available;
    }
    positionInRow = new int[squares];
    for(size_t k = 0; k < squares; k++) {
        positionInRow[k] = -1;
    }
    
    howMany = 0;
}

void chessBoard::printBoard() {
    howMany++;
    cout << "\n";
    for(size_t row = 0; row < squares; row++) {
        for(size_t col = 0; col < squares; col++) {
            if (col == positionInRow[row]) 
                cout << " O ";
            else
                cout << " X ";
        }
        cout << '\n';
    } 
    cout << "\n\n";
}


void chessBoard::putQueen(int row) {
    for(size_t col = 0; col < squares; col++) {
        if (column[col] == available && leftDiagonal[row + col] == available &&
            rightDiagonal[row - col + norm] == available) {
            //Mark all col and diagonals unavailable
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row + col] = !available;
            rightDiagonal[row - col + norm] = !available;

            if (row < squares - 1) { 
                putQueen(row + 1);
            }
            else {
                //sucess find a solution
                //Output the result and increment count
                printBoard();
            }
            column[col] = available;
            leftDiagonal[row + col] = available;
            rightDiagonal[row - col + norm] = available;
        }
    }
}

void chessBoard::findSolutions() {
    putQueen(0);
    cout << "\nThere are " << howMany << " solutions in total\n";
}

int main() {
    chessBoard C(8);
    C.findSolutions(); 
}
