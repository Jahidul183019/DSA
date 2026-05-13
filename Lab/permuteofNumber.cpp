#include <iostream>
using namespace std;

bool isValid(int pos,char ch){
    int digit=ch-'0';

    return pos%2==digit%2;

}


void permute(string s,int idx){
    if(idx==s.size()){
        cout<<s<<endl;
        return;
    }

    for(int i=idx;i<s.size();i++){
        

         swap(s[idx], s[i]);

         if(isValid(idx, s[idx])) {
            permute(s, idx + 1);
        }

        swap(s[idx], s[i]);
    }
}
int main() {
    string s;
    cin >> s;

    permute(s,0);

    return 0;
}