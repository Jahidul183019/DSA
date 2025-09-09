#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getMaxSum(vector<vector<int>> mat, int rows, int cols) {
    int maxRowSum = INT_MIN;

    for (int i = 0; i < rows; i++) {
        int rowSumI = 0;
        for (int j = 0; j < cols; j++) {
            rowSumI += mat[i][j];
        }
        maxRowSum = max(maxRowSum, rowSumI);
    }
    return maxRowSum;
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

    cout << getMaxSum(mat, rows, cols) << endl;

    return 0;
}
