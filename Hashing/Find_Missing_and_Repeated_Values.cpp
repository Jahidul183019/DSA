#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//Leetcode 2965

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        unordered_set<int>s;

        int n=grid.size();
        int a,b;

        int expSum=0,actualSum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actualSum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a=grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expSum=(n*n)*(n*n+1)/2;
        b=expSum+a-actualSum;
        ans.push_back(b);
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter grid size (n for n x n): ";
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    cout << "Enter grid elements row-wise:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    vector<int> result = sol.findMissingAndRepeatedValues(grid);
    cout << "Repeated value: " << result[0] << endl;
    cout << "Missing value: " << result[1] << endl;

    return 0;
}
