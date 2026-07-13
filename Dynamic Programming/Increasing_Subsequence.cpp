// https://cses.fi/problemset/task/1145/

#include <iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int lis(vector<int>&arr,int n){
    vector<int> tail;
 
    for (int x : arr) {
    auto it = lower_bound(tail.begin(), tail.end(), x);
 
    if (it == tail.end())
        tail.push_back(x);
    else
        *it = x;
}
 
return tail.size();
}
int main() {
    int n;
    cin>>n;
 
    vector<int>arr(n,0);
 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
 
    cout<<lis(arr,n)<<endl;
    return 0;
