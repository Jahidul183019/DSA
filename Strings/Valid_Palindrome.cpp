//Leetcode 125
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlphaNum(char ch){
        if(ch >= '0' && ch <= '9' || (tolower(ch) >='a' && tolower(ch) <= 'z')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int st=0,end=s.length()-1;

        while(st<end){
            if(!isAlphaNum(s[st])){
                st++;
                continue;
            }
            if(!isAlphaNum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string: ";
    cin >> input;  // cin stops at space

    if(sol.isPalindrome(input)){
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
