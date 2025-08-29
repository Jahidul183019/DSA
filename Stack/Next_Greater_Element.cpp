/*
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Time & Space Complexity : O(n)

int main(){
    vector<int> arr ={6,8,0,1,3};

    //Next Greater Element
    stack<int>s;
    vector<int>ans(arr.size(),0);

    for(int i = arr.size()-1;i>=0;i--){
        while(s.size()>0 && s.top() <= arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }

    //print
    for(int val : ans){
        cout << val << " ";
    }
    cout<<endl;

    return 0;
}
*/

//Leetcode 496

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int>m;//nums2,NexGreater
        stack<int>s;

        for(int i=nums2.size()-1;i>=0;i--){
            while(s.size()>0 && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                m[nums2[i]]=-1;
            }else{
                m[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        vector <int> ans;

        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};

int main() {
    int n1, n2;
    cin >> n1;
    vector<int> nums1(n1);
    for(int i=0;i<n1;i++) cin >> nums1[i];

    cin >> n2;
    vector<int> nums2(n2);
    for(int i=0;i<n2;i++) cin >> nums2[i];

    Solution sol;
    vector<int> ans = sol.nextGreaterElement(nums1, nums2);

    for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
