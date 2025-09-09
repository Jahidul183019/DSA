#include <iostream>
#include <vector>
using namespace std;

//Leetcode 54
//Time Complexity : O(m*n)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {
            // top
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }

            // right
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }

            // bottom
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) {
                    break;
                }
                ans.push_back(mat[erow][j]);
            }

            // left
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) {
                    break;
                }
                ans.push_back(mat[i][scol]);
            }

            srow++; erow--; scol++; ecol--;
        }
        return ans;
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter matrix elements row-wise:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    Solution sol;
    vector<int> result = sol.spiralOrder(mat);

    cout << "Spiral Order: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
