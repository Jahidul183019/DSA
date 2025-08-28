#include <iostream>
using namespace std;

/*
Leetcode 560
Time Complexity: O(2^n) 
Space Complexity: O(n)    
*/

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.fib(n) << endl;
    return 0;
}
