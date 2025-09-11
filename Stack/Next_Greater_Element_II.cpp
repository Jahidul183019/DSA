#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Leetcode 503
//Time & Space Complexity : O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<int>s;

        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()] <= nums[i%n]){
                s.pop();
            }
            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
