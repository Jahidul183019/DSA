#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Leetcode 84
//Time & Space Complexity : O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n,0);//left smaller nearest
        vector<int>right(n,0);//right smaller nearest
        stack<int>s;

        //right smaller : O(n)
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        //left smaller : O(n)
        for(int i=0;i<n;i++){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){//O(n)
            int width = right[i] - left[i] - 1;
            int currArea= heights[i] * width;

            ans=max(ans,currArea);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of bars in histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights: ";
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    Solution sol;
    int result = sol.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}
