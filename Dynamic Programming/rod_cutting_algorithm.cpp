#include <iostream>
#include <vector>

using namespace std;

int rodCut(vector<int>price, int n){
     vector<int>dp(n+1,0);

     dp[0]=0;

     for(int i=1;i<=n;i++){
        int maxProfit=-1;

        for(int j=1;j<=i;j++){
            int profit=price[j-1]+dp[i-j];

            if(profit>maxProfit){
                maxProfit=profit;
            }
        }
        dp[i]=maxProfit;
     }
     return dp[n];
}

int main()
{   
    int n;
    cin>>n;

    vector<int>price(n);

   for(int i=0;i<n;i++){
    cin>>price[i];
   }

   cout<<rodCut(price,n)<<endl;

    return 0;
}
