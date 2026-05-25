#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Item{
public:
    int value;
    int weight;

    Item(int v,int w){
        value=v;
        weight=w;
    }
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(vector<Item> &items, int capacity){
    sort(items.begin(),items.end(),compare);

    double totalProfit=0;

    for(int i=0;i<items.size();i++){
        if(capacity>=items[i].weight){
            totalProfit+=items[i].value;
            capacity-=items[i].weight;
        }
        else{
            totalProfit+=((double)items[i].value / items[i].weight) * capacity;
            break;
        }
    }
    return totalProfit;
}
int main(){
    int n,capacity;

    cin>>n>>capacity;

    vector<Item>items;

    for(int i=0;i<n;i++){
        int v,w;
        cin>>v>>w;

        items.push_back(Item(v,w));
    }

    double result = fractionalKnapsack(items, capacity);

    cout<<"Maximum Profit : "<< result << endl;
    
    return 0;
}