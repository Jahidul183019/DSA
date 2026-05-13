#include <iostream>
#include<vector>
using namespace std;

bool isValid(int pos, char ch) {
    int digit = ch - '0';
    return pos % 2 == digit % 2;
}

int sum(string str){
    
    int s=0;

    for(int x : str){
        s+=(x-'0');
    }
}
void f(string curr, vector<char> arr) {
    if (curr.size() == 5 && sum(curr)<30) {
        cout << curr << endl;
        return;
    }

    int pos = curr.size();

    for (int i = 0; i < arr.size(); i++) {

        if(!isValid(pos,arr[i])) continue;

        char c=arr[i];

        curr+=c;
        vector<char>newArr=arr;

        newArr.erase(newArr.begin()+i);

        f(curr,newArr);
    }
}

int main() {
    vector<char> arr = {'1','2','3','4','5','6','7','8','9'};

    string curr = "";

    f(curr, arr);

    return 0;
}