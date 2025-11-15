#include <iostream>
#include<vector>

using namespace std;

void heapify(vector<int>&arr,int n,int i){
    // Time Complexity of heapify = O(log n)
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
 
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);  // O(log n)
    }
}

void heapSort(vector<int>&arr){
    int n=arr.size();

    // Build max heap: O(n)
    for(int i=n/2-1 ;i>=0;i--){
        heapify(arr,n,i);
    }

    // Extract elements: n times heapify → O(n log n)
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);   // O(log n)
    }
}

int main(){
    vector<int> arr = {7,3,2,6,1,5};

    heapSort(arr);

    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    return 0;
}
