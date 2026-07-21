#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long matrixChainMultiplication(vector<int>& p) {

    int n = p.size() - 1;

    vector<vector<long long>> dp(
        n + 1,
        vector<long long>(n + 1, 0)
    );

    // Length of matrix chain
    for (int len = 2; len <= n; len++) {

        for (int i = 1; i + len - 1 <= n; i++) {

            int j = i + len - 1;

            dp[i][j] = LLONG_MAX;

            // Try every split
            for (int k = i; k < j; k++) {

                long long cost =
                    dp[i][k]
                    + dp[k + 1][j]
                    + 1LL * p[i - 1] * p[k] * p[j];

                dp[i][j] =
                    min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main() {

    int n;
    cin >> n;

    vector<int> p(n + 1);

    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    cout << matrixChainMultiplication(p) << endl;

    return 0;
}