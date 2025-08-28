#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Leetcode 1

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i=0;i<arr.size();i++){
            int first=arr[i];
            int sec=target-arr[i];

            if(m.find(sec)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
            m[first]=i;
        }    
        return ans;
    }
};

int main() {
    Solution sol;
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i=0;i<n;i++) cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    vector<int> result = sol.twoSum(nums, target);

    if(result.size() == 2){
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
