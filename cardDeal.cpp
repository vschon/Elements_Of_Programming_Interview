#include <iostream>
#include <vector>

using namespace std;

double calculatePrice(double r, double b, vector<vector<double> >& expectedMatrix) {
    //base case
    cout << "Calling r = " << r << " b = " << b << endl;
    if (r == 0 && b == 0) 
        return 0;
    if (r == -1 || b == -1)
        return 0;
    if (expectedMatrix[r][b] != -1.0)
        return expectedMatrix[r][b];
    
    double currentPrice = b - r;
    double expectedPrice = (r/(r+b)) * calculatePrice(r-1, b, expectedMatrix) + (b/(r+b)) * calculatePrice(r, b-1, expectedMatrix);
    double result = expectedPrice > currentPrice ? expectedPrice : currentPrice;

    expectedMatrix[r][b] = result;

    cout << " result = " << result << endl;

    return result;
}

int main() {

    vector<vector<double> > expectedMatrix(27, vector<double>(27, -1.0));
    cout << "begin" << endl;

    cout << calculatePrice(26, 26, expectedMatrix) << endl;

    return 0;
}
