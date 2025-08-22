#include<iostream>
#include<vector>
using namespace std;

      bool isValid(vector<int>arr,int n,int k,int maxAllowedPages){
          int pages=0,students=1;
          
          for(int i=0;i<n;i++){
              
          if(arr[i]>maxAllowedPages){
              return false;
          }
          
          if(pages+arr[i]<=maxAllowedPages){
              pages+=arr[i];
          }
          else{
              students++;
              pages=arr[i];
          }
          }
          return students > k ? false : true ;
      }
      
      int findPages(vector<int> &arr, int k) {
          int n=arr.size();
          
          if(k > n){
              return -1;
          }
          
          int sum=0;
          for(int i=0;i<n;i++){
              sum+=arr[i];
          }
          
          
          int st=0,end=sum,ans=-1;
          
          while(st<=end){
               int mid=st+(end-st)/2;
               
               if(isValid(arr,n,k,mid)){
                   ans=mid;
                   end=mid-1;
               }
               else{
                   st=mid+1;
               }
               
          }
          return ans;
      }

  int main(){
    int n;
    cout << "Enter the number of books: ";
    cin >> n;

    vector<int> arr(n); // Declaring vector with size n
    cout << "Enter the pages of books: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cout << "Enter the number of students: ";
    cin >> m;

    int result = findPages(arr, m);
    
    if (result == -1) {
        cout << "Allocation not possible" << endl;
    } else {
        cout << "Minimum number of maximum pages: " << result << endl;
    }

    return 0;
}