#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

//Leetcode 387
// TC : O(n)
// SC : O(n)

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
        queue<int>Q;

        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                Q.push(i);
            }
            m[s[i]]++;
        }

        while(Q.size()>0 && m[s[Q.front()]]>1){
            Q.pop();
        }
        
        return Q.empty() ? -1 : Q.front();
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int idx = sol.firstUniqChar(s);

    if (idx == -1)
        cout << "No unique character found.\n";
    else
        cout << "First unique character is '" << s[idx] 
             << "' at index " << idx << endl;

    return 0;
}
