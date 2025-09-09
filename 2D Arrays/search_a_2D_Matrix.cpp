#include <iostream>
#include <vector>
using namespace std;

//Leetcode 74
//Time Complexity : O(log(m*n))

class Solution {
public:
    bool searchInRow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();
        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == mat[row][mid]) {
                return true;
            } else if (target > mat[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int target) {
        // BS on tot row
        int m = mat.size(), n = mat[0].size();
        int startRow = 0, endRow = m - 1;

        while (startRow <= endRow) {
            int midRow = startRow + (endRow - startRow) / 2;

            if (target >= mat[midRow][0] && target <= mat[midRow][n - 1]) {
                return searchInRow(mat, target, midRow);
            } else if (target >= mat[midRow][n - 1]) {
                // down => right
                startRow = midRow + 1;
            } else {
                // up => left
                endRow = midRow - 1;
            }
        }
        return false;
    }
};

int main() {
    int m, n, target;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter matrix elements row-wise:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    cout << "Enter target: ";
    cin >> target;

    Solution sol;
    bool found = sol.searchMatrix(mat, target);

    if (found)
        cout << "Target found in the matrix." << endl;
    else
        cout << "Target not found in the matrix." << endl;

    return 0;
}
