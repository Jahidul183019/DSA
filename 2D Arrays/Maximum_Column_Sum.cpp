#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getMaxColSum(vector<vector<int>> mat, int rows, int cols) {
    int maxColSum = INT_MIN;

    for (int j = 0; j < cols; j++) {
        int colSumJ = 0;
        for (int i = 0; i < rows; i++) {
            colSumJ += mat[i][j];
        }
        maxColSum = max(maxColSum, colSumJ);
    }
    return maxColSum;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> mat(rows, vector<int>(cols));

    // input matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    cout << getMaxColSum(mat, rows, cols) << endl;

    return 0;
}
