#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// =====================
// Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(n)
// =====================
int lisRec(vector<int>& arr, int idx, int prev) {
    if (idx == arr.size())
        return 0;

    // Don't take current element
    int notTake = lisRec(arr, idx + 1, prev);

    // Take current element (if possible)
    int take = 0;
    if (prev == -1 || arr[idx] > arr[prev])
        take = 1 + lisRec(arr, idx + 1, idx);

    return max(take, notTake);
}

// =====================
// Memoization (Top-Down DP)
// Time Complexity: O(n²)
// Space Complexity: O(n²)
// =====================
int lisMemo(vector<int>& arr, int idx, int prev,
            vector<vector<int>>& dp) {

    if (idx == arr.size())
        return 0;

    // Already computed
    if (dp[idx][prev + 1] != -1)
        return dp[idx][prev + 1];

    // Don't take current element
    int notTake = lisMemo(arr, idx + 1, prev, dp);

    // Take current element
    int take = 0;
    if (prev == -1 || arr[idx] > arr[prev])
        take = 1 + lisMemo(arr, idx + 1, idx, dp);

    return dp[idx][prev + 1] = max(take, notTake);
}

// =====================
// Bottom-Up DP (Tabulation)
// Time Complexity: O(n²)
// Space Complexity: O(n)
// =====================
int lisBottomUp(const vector<int>& arr) {

    int n = arr.size();

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {

            if (arr[i] > arr[prev]) {
                dp[i] = max(dp[i], dp[prev] + 1);
            }

        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Recursive      : "
         << lisRec(arr, 0, -1) << endl;

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    cout << "Memoization    : "
         << lisMemo(arr, 0, -1, dp) << endl;

    cout << "Bottom-Up DP   : "
         << lisBottomUp(arr) << endl;

    return 0;
}