// https://cses.fi/problemset/task/1638

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int editDistance(string s1,string s2) {
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

         // Transform first i characters into empty string
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        // Transform empty string into first j characters
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i=1;i<=n;i++) {
        for (int j= 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] =  dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({
                        dp[i - 1][j],     // Delete
                        dp[i][j - 1],     // Insert
                        dp[i - 1][j - 1]  // Replace
                    });
            }
        }
    }

    return dp[n][m];
        
    }
};

int main() {
    Solution obj;

    string s1,s2;
    cin>>s1>>s2;

    vector<int>sol;
    int ans = obj.editDistance(s1,s2);

    cout << ans << endl;

    return 0;
}