#include <iostream>
#include <vector>

using namespace std;

int parent(int i){
    return (i-1)/2;
}

int leftChild(int i){
    return 2*i+1;
}

int rightChild(int i){
    return 2*i+2;
}

void shiftUp(int i,vector<int>&arr){
    while(i>0 && arr[parent(i)]<arr[i]){
        swap(arr[i],arr[parent(i)]);
        i=parent(i);
    }
}

void shiftDown(int i,vector<int>&arr,int size){
    int largestIdx=i;

    int l=leftChild(i);
    int r=rightChild(i);

    if(l<size && arr[l]>arr[largestIdx]){
        largestIdx=l;
    }
    if(r<size && arr[r]>arr[largestIdx]){
        largestIdx=r;
    }

    if(i!=largestIdx){
        swap(arr[i],arr[largestIdx]);
        shiftDown(largestIdx,arr,size);
    }
}

void insert(int val,vector<int>&arr){
    arr.push_back(val);
    shiftUp(arr.size()-1,arr);
}

int pop(vector<int>&arr){
    int size=arr.size();
    if(size==0){
        return -1;
    }
    int result=arr[0];
    arr[0]=arr[size-1];
    arr.pop_back();
    shiftDown(0,arr,arr.size());

    return result;
}

int getMax(vector<int>&arr){
    if(arr.empty()){
         return -1;
    }
    return arr[0];
}

void printHeap(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> pq;

    insert(45, pq);
    insert(20, pq);
    insert(14, pq);
    insert(12, pq);
    insert(31, pq);
    insert(7, pq);
    insert(11, pq);
    insert(13, pq);
    insert(7, pq);

    cout << "Priority Queue after inserts: ";
    printHeap(pq);

    cout << "Current max element: " << getMax(pq) << endl;

    pop(pq) ;
    cout << "Priority Queue after extracting max: ";
    printHeap(pq);
    return 0;
}
