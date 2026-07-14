#include <iostream>
#include <vector>
using namespace std;

vector<int> value, weight;
vector<vector<int>> dp;
int n;

int knap(int i, int rem)
{
    if (i == n || rem <= 0)
        return 0;

    if (dp[i][rem] != -1)
        return dp[i][rem];

    int taken = 0;
    int notTaken = 0;

    if (weight[i] <= rem)
        taken = value[i] + knap(i + 1, rem - weight[i]);

    notTaken = knap(i + 1, rem);

    dp[i][rem] = max(taken, notTaken);

    return dp[i][rem];
}

int main()
{
    int capacity;

    cin >> n >> capacity;

    value.resize(n);
    weight.resize(n);

    for (int i = 0; i < n; i++)
        cin >> value[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    dp.assign(n + 1, vector<int>(capacity + 1, -1));

    cout << "Maximum Profit = " << knap(0, capacity) << endl;

    return 0;
}