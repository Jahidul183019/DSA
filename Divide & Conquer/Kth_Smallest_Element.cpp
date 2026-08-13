#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int> &arr, int st, int end){
    int pivot=arr[end];
    int idx=st-1;
    
    for(int j=st;j<end;j++){
        if(arr[j] <= pivot){ // If we want to sort this array in descending order : if(arr[j] >= pivot)
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}

int quickSelect(vector<int> &arr , int st ,int end,int k){
    if(st == end){
        return arr[st];
    }

    if(st<end){
        int pivIdx = partition(arr, st, end);
        
        if(pivIdx==k) return arr[pivIdx];

        // k is on the left
        if(pivIdx>k)
             return  quickSelect(arr,st,pivIdx-1,k);

        // k is on the right
        else{
              return quickSelect(arr,pivIdx+1,end,k);
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {12,31,35,8,32,1};

    int k = 3; 

    int ans=quickSelect(arr,0,arr.size()-1,k-1);

    cout << k << "th smallest element = " << ans << endl;

    

    return 0;
}