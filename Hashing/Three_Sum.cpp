#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Leetcode 15
//TC(nlogn+n^2)
//SC:O(Unique Triplets)
//Two Pointer Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j=i+1,k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];

                if(sum<0) {j++;}
                else if (sum>0) {k--;}
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;

                    while(j<k && nums[j]==nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];

    vector<vector<int>> result = sol.threeSum(nums);

    for(auto &triplet : result){
        for(int x : triplet) cout << x << " ";
        cout << endl;
    }

    return 0;
}
