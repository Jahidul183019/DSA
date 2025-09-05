#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//Leetcode 239
//Time Complexity : O(n)
//Space Complexity : O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {//O(n)
        deque<int>dq;
        vector<int>res;

        //1st window
        for(int i=0;i<k;i++){//O(k)
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for(int i=k;i<nums.size();i++){//O(n-k)
            res.push_back(nums[dq.front()]);

            //remove not part of window
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            //remove the smaller vals
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
