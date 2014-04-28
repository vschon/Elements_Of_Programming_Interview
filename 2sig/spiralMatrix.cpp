#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<int >> Matrix;

void printMatrix(Matrix& spiral) {
    int n = spiral.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << spiral[i][j] << " ";
        }
        cout << "\n";
    }

    cout << endl;
}

void spiralMatrixHelper(Matrix& spiral, int begin, int n, int count) {
    int row = begin;
    int col = begin;

    if (n == 1) {
        spiral[begin][begin] = count++;
        return;
    }
    else if (n == 0) {
        return;
    }

    for(; col < begin + n; col++)
        spiral[row][col] = count++;

    printMatrix(spiral);

    for(++row, --col; row < begin + n; row++)
        spiral[row][col] = count++;

    printMatrix(spiral);

    for(--col, --row; col >= begin; col--)
        spiral[row][col] = count++;

    for(--row, ++col; row > begin; row--)
        spiral[row][col] = count++;

    printMatrix(spiral);
    spiralMatrixHelper(spiral, begin + 1, n - 2, count);

}


void spiralMatrix(int n) {
    Matrix spiral(n, vector<int>(n, -1));
    spiralMatrixHelper(spiral, 0, n, 1);
    printMatrix(spiral);
    
}

int main() {

    int n = 6; 

    spiralMatrix(n);
    
    return 0;
}
