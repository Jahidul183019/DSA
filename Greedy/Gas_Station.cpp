/*
#include <iostream>
#include <vector>
using namespace std;

//Leetcode 134 
//TC :O(n)
//SC:O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas=0,totCost=0;

        for(int val : gas){
            totGas+=val;
        }
        for(int val : cost){
            totCost+=val;
        }

        if(totGas<totCost){
            return -1;
        }
        
        //Unique solution always exist
        int start=0,currGas=0;
        for(int i=0;i<gas.size();i++){
           currGas+=(gas[i]-cost[i]);
           if(currGas<0){
               start=i+1;
               currGas=0;
           }
        }
        return start;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of gas stations: ";
    cin >> n;

    vector<int> gas(n), cost(n);
    cout << "Enter gas values: ";
    for(int i=0; i<n; i++) cin >> gas[i];

    cout << "Enter cost values: ";
    for(int i=0; i<n; i++) cin >> cost[i];

    int result = sol.canCompleteCircuit(gas, cost);

    if(result == -1) {
        cout << "No valid starting station." << endl;
    } else {
        cout << "Start at station index: " << result << endl;
    }

    return 0;
}
*/

                                    //Optimized Version

                                    #include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas=0,totCost=0;
         
        //Unique solution always exist
        int start=0,currGas=0;
        for(int i=0;i<gas.size();i++){
            totGas+=gas[i];
            totCost+=cost[i];
            currGas+=(gas[i]-cost[i]);
            if(currGas<0){
                start=i+1;
                currGas=0;
            }
        }
        return totGas<totCost ? -1 : start ;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of gas stations: ";
    cin >> n;

    vector<int> gas(n), cost(n);
    cout << "Enter gas values: ";
    for(int i=0; i<n; i++) cin >> gas[i];

    cout << "Enter cost values: ";
    for(int i=0; i<n; i++) cin >> cost[i];

    int result = sol.canCompleteCircuit(gas, cost);

    if(result == -1) {
        cout << "No valid starting station." << endl;
    } else {
        cout << "Start at station index: " << result << endl;
    }

    return 0;
}
