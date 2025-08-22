#include<iostream>
#include<vector>
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

void quickSort(vector<int> &arr , int st ,int end){// Avg TC    : O(n^2)
                                                   // Worst TC  : O(n^2)
                                                   // Space Complexity : O(1)
    if(st<end){
        int pivIdx = partition(arr, st, end);
        
        quickSort(arr, st, pivIdx - 1); //left half
        quickSort(arr, pivIdx + 1, end); //right half
    }
}
int main(){
    vector<int> arr = {12,31,35,8,32,1};

    quickSort(arr,0,arr.size()-1);

    for(int val : arr){
        cout<<val<<" ";
    }

    return 0;
}