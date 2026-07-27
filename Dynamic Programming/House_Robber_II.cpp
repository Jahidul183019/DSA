// Leetcode 213

class Solution {
public:
  int helper(vector<int> &nums, int st, int end) { // house robber I logic
    int n = nums.size();

    if (n == 1)
      return nums[0];

    vector<int> dp(n - 1);

    dp[0] = nums[st];
    dp[1] = max(nums[st], nums[st + 1]);

    for (int i = st + 2, j = 2; i <= end; i++, j++) {
      dp[j] = max(dp[j - 1], dp[j - 2] + nums[i]);
    }
    return dp[n - 2];
  }
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    return max(helper(nums, 0, nums.size() - 2),
               helper(nums, 1, nums.size() - 1));
  }
};

// Space Optimization
class Solution {
public:
  int helper(vector<int> &nums, int st, int end) { // house robber I logic
    int n = nums.size();

    if (n == 1)
      return nums[0];

    int prev1 = nums[st];
    int prev2 = max(nums[st], nums[st + 1]);
    int result = prev2;
    for (int i = st + 2; i <= end; i++) {
      result = max(prev2, prev1 + nums[i]);
      prev1 = prev2;
      prev2 = result;
    }
    return result;
  }

  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }

    return max(helper(nums, 0, nums.size() - 2),
               helper(nums, 1, nums.size() - 1));
  }
};