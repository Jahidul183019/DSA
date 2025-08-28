#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//Leetcode 131
class Solution {
public:
    bool isPalindrome(string &s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s2 == s;
    }

    void getAllParts(string s, vector<string>& partitions, vector<vector<string>>& ans){
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }
        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0, i + 1);
            if(isPalindrome(part)){
                partitions.push_back(part);
                getAllParts(s.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(s, partitions, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<vector<string>> result = sol.partition(s);

    cout << "Palindrome partitions are:\n";
    for (auto &vec : result) {
        for (auto &part : vec) {
            cout << part << " ";
        }
        cout << endl;
    }

    return 0;
}
