#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Leetcode 18
//Two Pointer Approach
//TC : O(nlogn + n^3 )
//SC : O(UniqueGroups)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;){
                int p=j+1,q=n-1;

                while(p<q){
                    long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];

                    if(sum<target) p++;
                    else if (sum>target) q--;
                    else{//sum==target
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        p++,q--;

                        while(p<q && nums[p]==nums[p-1]) p++;
                    }
                }
                j++;
                while(j<n && nums[j]==nums[j-1]) j++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    cin >> target;

    vector<vector<int>> result = sol.fourSum(nums, target);

    for(auto &quad : result){
        for(int x : quad) cout << x << " ";
        cout << endl;
    }

    return 0;
}
