#include <iostream>
#include <vector>
using namespace std;

/*
Leetcode 704
Time Complexity: O(log n)
Space Complexity: O(log n)
*/

class Solution {
public:
    int binSearch(vector<int>& arr, int tar, int st, int end){
        if(st<=end){
            int mid = st + (end-st)/2;

            if(arr[mid]==tar) return mid;
            else if(arr[mid]<tar){
                return binSearch(arr, tar, mid+1, end);
            }else{
                return binSearch(arr, tar, st, mid-1);
            }
        }
        return -1;
    }

    int search(vector<int>& arr, int tar) {
        return binSearch(arr, tar, 0, arr.size()-1);
    }
};

int main() {
    Solution sol;
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    cin >> target;

    cout << sol.search(arr, target) << endl;
    return 0;
}
