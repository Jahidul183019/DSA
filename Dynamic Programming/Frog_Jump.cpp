/*

Frog Jump

You are given an array height of size n, where height[i] represents the height of the i-th stair (1-indexed). A frog starts on the first stair and wants to reach the last stair.

From any stair i, the frog has two options:

	•	Jump to stair (i + 1)
	•	Jump to stair (i + 2)

The cost of a jump is the absolute difference in height between the two stairs involved.

Find the minimum total cost required for the frog to reach the last stair.

Example

Input:
height = [30, 20, 50, 10, 40]
n = 5

Output:
30

Explanation:
One optimal path is: stair 1 (30) → stair 3 (50) → stair 5 (40)

	•	Jump from stair 1 to stair 3: cost = |50 − 30| = 20
	•	Jump from stair 3 to stair 5: cost = |40 − 50| = 10

Total cost = 20 + 10 = 30, which is the minimum possible.

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minCost(vector<int>&height){
    int n=height.size();

    if(n==1) return 0;

    vector<int>dp(n); // dp[i] => min cost to reach last stair i

    dp[0]=0;
    dp[1]=abs(height[1]-height[0]);
    for(int i=2;i<n;i++){
        int jump1=dp[i-1]+abs(height[i]-height[i-1]);
        int jump2=dp[i-2]+abs(height[i]-height[i-2]);
        dp[i]=min(jump1,jump2);
    }

    return dp[n-1];
}

int main(){
    int n;
    cin>>n;

    vector<int>height(n+1);

    for(int i=0;i<n;i++){
        cin>>height[i];
    }

    cout<<minCost(height)<<endl;
    
    return 0;
}