/*
Given a 2D array arr[n][n] such that arr[i][j] = 1 means the ith person knows the jth person, the task is to find the celebrity.

A celebrity is a person who is known to all but doesn’t know anyone.

Return the index of the celebrity, if there is no celebrity return -1.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Time & Space Complexity : O(n)
int getCelebrity(vector<vector<int>>arr){
  int n=arr.size();
  stack<int>s;

  for(int i=0;i<n;i++){
    s.push(i);
  }

  while(s.size()>1){
    int i=s.top();
    s.pop();

    int j=s.top();
    s.pop();

    if(arr[i][j]==0){
        s.push(i);
    }else{
        s.push(j);
    }
  }
  int celeb = s.top();

  for(int i=0;i<n;i++){
    if(i!=celeb && arr[i][celeb]==0 || arr[celeb][i]==1){
        return -1;
    }
  }
  return celeb;
}
int main(){
    vector<vector<int>>arr={{0,1,0},{0,0,0},{0,1,0}};

    int ans=getCelebrity(arr);
    
    cout<<"Celebrity is : "<<ans<<endl;

    return 0;
}