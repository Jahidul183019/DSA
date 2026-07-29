#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool compare(vector<int>&a,vector<int>&b){
    double a1=(1.0*a[0])/a[1];
    double b1=(1.0*b[0])/b[1];

    return a1>b1;
}

double fractionalKnapsack(vector<vector<int>>&items,int K){
   sort(items.begin(),items.end(),compare);

   int maxVal=0;

   for(auto& item : items){
        int val=item[0];
        int wt=item[1];

        if(wt<=K){
            maxVal+=val;
            K-=wt;
        }else{
            maxVal+=((double)val/wt)*K;
            break;
        }
   }
   return maxVal;
}

int main() {
    int n, K;

    cin >> n >> K;

    vector<vector<int>> items;

    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;

        items.push_back({v, w});   // {value, weight}
    }

    double result = fractionalKnapsack(items, K);

    cout << "Maximum Profit : " << result << endl;

    return 0;
}