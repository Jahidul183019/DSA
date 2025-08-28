#include <iostream>
#include <climits>
using namespace std;

//Leetcode 9

class Solution {
public:
    int reverse(int n) {
        int revNum=0;

        while(n !=0){
            int dig = n%10;

            if(revNum > INT_MAX/10 || revNum < INT_MIN/10){
                return 0;
            }
            revNum = (revNum * 10) + dig;
            n = n/10;
        }
        return revNum;
    }

    bool isPalindrome(int n) {
        if(n<0){
            return false;
        }
        int revNum=reverse(n);

        return revNum==n;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    if(sol.isPalindrome(n)) {
        cout << n << " is a Palindrome." << endl;
    } else {
        cout << n << " is NOT a Palindrome." << endl;
    }

    return 0;
}

