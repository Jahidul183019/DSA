//Leetcode 852
//TC O(logN)

#include <iostream>
#include <vector>
using namespace std;

int peakIndexMountainArray (vector<int> &A){

    int st = 0, end = A.size()-1;

    while(st <= end){

        int mid = st + (end-st)/2;

        if(A[mid-1] < A[mid] && A[mid] > A[mid+1]){
            return mid;
        }

        else if(A[mid-1] < A[mid]){     //right
            st = mid+1;
        }

        else{       //left
            end = mid-1;
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {0,2,5,7,6,3,1};
    cout << peakIndexMountainArray(arr) << endl;
    return 0;
}
