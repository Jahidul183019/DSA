// Leetcode 198

// Recursive Approach : TC : O(2^n)
class Solution {
public:
  int solve(vector<int> &nums, int i) {

    // No house left
    if (i < 0) {
      return 0;
    }

    // skip current house
    int skip = solve(nums, i - 1);

    // rob current house
    int take = nums[i] + solve(nums, i - 2);

    return max(skip, take);
  }

  int rob(vector<int> &nums) {
    int n = nums.size();

    return solve(nums, n - 1);
  }
};

// Memorization DP
class Solution {
public:
  int solve(vector<int> &nums, int i, vector<int> &dp) {
    // No house left
    if (i < 0) {
      return 0;
    }

    if (dp[i] != -1) {
      return dp[i];
    }
    // Option 1: skip current house
    int skip = solve(nums, i - 1, dp);

    // Option 2: rob current house
    int take = nums[i] + solve(nums, i - 2, dp);

    return dp[i] = max(take, skip);
  }

  int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(nums, n - 1, dp);
  }
};

// Tabulation DP
class Solution {
public:
  int rob(vector<int> &nums) { // TC : O(n)
    int n = nums.size();

    if (n == 1)
      return nums[0];

    vector<int> dp(n, -1);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[n - 1];
  }
};

// Space Optimization : SC : O(1)
class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();

    if (n == 1)
      return nums[0];

    int prev1 = nums[0];
    int prev2 = max(nums[0], nums[1]);
    int result = prev2;

    for (int i = 2; i < n; i++) {
      result = max(prev2, nums[i] + prev1);
      prev1 = prev2;
      prev2 = result;
    }
    return result;
  }
};
