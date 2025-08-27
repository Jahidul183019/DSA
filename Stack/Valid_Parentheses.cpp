// Leetcode 20
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char>st;

        for(int i=0;i<str.size();i++){
            if(str[i]=='(' || str[i]=='{' || str[i]=='['){//opening
                st.push(str[i]);
            }else{//closing
                if(st.size()==0){
                    return false;
                }
                if((st.top() == '(' && str[i] == ')') || 
                   (st.top() == '{' && str[i] == '}') || 
                   (st.top() == '[' && str[i] == ']')){
                    st.pop();
                }else{//no match
                   return false;
                }
            }
        }
        return st.size() == 0;
    } 
};

int main() {
    string s;
    cin >> s;  
    Solution obj;
    if (obj.isValid(s))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    return 0;
}
