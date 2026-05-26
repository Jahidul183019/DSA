#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job{
public:
    int value;
    int deadlines;

    Job(int v,int d){
        value=v;
        deadlines=d;
    }
};

bool compare(Job a,Job b){
    return a.value > b.value;
}
int maxProfit(vector<Job>&jobs,int maxVal){
    int totProfit=0;
    int cnt=0; 
    sort(jobs.begin(),jobs.end(),compare);

    vector<bool>slot(maxVal+1, false);

    for(int i=0;i<jobs.size();i++){
        for(int j=jobs[i].deadlines;j>=1;j--){
            if(!slot[j]){
                slot[j]=true;
                totProfit+=jobs[i].value;
                break;
            }
        }
    }
  return totProfit;
}
int main(){
    int n;
    cin>>n;

    vector<Job>jobs;

    int maxVal=0;

    for(int i=0;i<n;i++){
        int v,d;
        cin>>v>>d;

        jobs.push_back(Job(v,d));
        maxVal=max(maxVal,d);
    }

    cout<<maxProfit(jobs,maxVal)<<endl;
    return 0;
}