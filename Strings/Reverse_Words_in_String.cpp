//Leetcode 151
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";

        reverse(s.begin(),s.end());

        for(int i=0;i<n;i++){
            string word="";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(word.length()>0){
                ans+=" "+word;
            }
        }
        return ans.substr(1);
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string: ";
    getline(cin, input);  // using getline to handle spaces

    string result = sol.reverseWords(input);

    cout << "Reversed words: " << result << endl;

    return 0;
}
