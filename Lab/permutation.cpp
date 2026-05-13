#include <iostream>
#include <vector>
using namespace std;

void getPerms(string s,int idx){
    if(idx==s.size()){
        cout<<s<<endl;
        return;
    }

    for(int i=idx;i<s.size();i++){
        swap(s[i],s[idx]);
        getPerms(s,idx+1);
        swap(s[i],s[idx]);
    }
}

int main() {
    string str;
    cin>>str;

    getPerms(str,0);

    return 0;
}