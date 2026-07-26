//Leetcode 70

//Recursive Approach
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2) return n;

        return climbStairs(n-1) + climbStairs(n-2);
    }
};

//Memorization DP
class Solution {
public:
    int helper(int n,vector<int>&dp){
       if(n==1 || n==2) return n;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=helper(n-1,dp) + helper(n-2,dp);
    }
    int climbStairs(int n) {
      vector<int>dp(n+1,-1);

      return helper(n,dp);
    }
};

//Tabulation DP
class Solution {
public:
    int climbStairs(int n) {
     if(n==1 || n==2) return n;
      vector<int>dp(n+1);

      dp[1]=1;
      dp[2]=2;

      for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
      }

      return dp[n];
    }
};

//Optimization Tabular DP SC:O(1)
class Solution {
public:
    int climbStairs(int n) {
     if(n==1 || n==2) return n;
      
      int prev2=1; // n-2
      int prev1=2; // n-1

      int result=prev1;
      for(int i=3;i<=n;i++){
        result=prev1+prev2;
        prev2=prev1;
        prev1=result;
      }

      return result;
    }
};