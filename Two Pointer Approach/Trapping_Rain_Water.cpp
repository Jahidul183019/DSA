/*
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

//Leetcode 42
//Time & Space Complexity : O(n)
//Prefix Array Approach

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (min(leftMax[i], rightMax[i]) - height[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << "Trapped water: " << sol.trap(height) << endl;

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Leetcode 42
//Time Complexity : O(n)
// Space Complexity : O(1)
//Two Pointer Approach

class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
       int ans = 0;
       int l = 0, r = n - 1;
       int lmax = 0, rmax = 0;

       while (l < r) {
           lmax = max(lmax, height[l]);
           rmax = max(rmax, height[r]);

           if (lmax < rmax) {
               ans += lmax - height[l];
               l++;
           } else {
               ans += rmax - height[r];
               r--;
           }
       }
       return ans;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << sol.trap(height) << endl;

    return 0;
}

