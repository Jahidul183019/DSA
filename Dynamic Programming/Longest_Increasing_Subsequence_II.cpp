// https://cses.fi/problemset/task/1748
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
int lisBottomUp(const vector<int>& arr) {

    int n = arr.size();

    vector<int> dp(n, 1);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {

            if (arr[i] > arr[prev]) {
                dp[i] = (dp[i]+dp[prev]) % MOD;
            }

        }
        ans=(ans+dp[i]) % MOD;
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout<<lisBottomUp(arr)<<endl;

    return 0;
}