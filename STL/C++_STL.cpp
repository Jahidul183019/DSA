#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
using namespace std;

// bool comparator(pair<int,int>p1,pair<int,int>p2){
//     if(p1.second < p2.second) return true;
//     else return false;
// }

bool comparator(pair<int,int>p1,pair<int,int>p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    
    if(p1.first < p2.first) return true;
    else return false;
    
}



int main(){                         // Vectors
    // vector<int>vec; //0
    // vector<int>vec ={1,2,3,4,5};
    // vector<int>vec(3,10);// Dynamic Programming - tabulation DP[][]
     
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);
    // vec.push_back(5);
    // vec.emplace_back(6);//Alternative of push_back

    // vec.pop_back();

    // cout<<vec.size()<<endl;//3
    // cout<<vec.capacity()<<endl;//4

    // vector<int>vec1 = {1,2,3,4,5};

    // vector<int>vec2(vec1);

    // vector<int>vec = {1,2,3,4,5};

    // vec.erase(vec.begin());
    // vec.erase(vec.begin()+2);
    // vec.erase(vec.begin()+1,vec.begin()+3);

    // vec.insert(vec.begin()+2,100);
    
    

    // cout<<"val at idx 2 "<<vec[2]<<" or "<<vec.at(2)<<endl;

    // cout<<"front " << vec.front() << endl;
    // cout<<"back " << vec.back() << endl;

    // vector<int>vec = {1,2,3,4,5};
    
    // vec.clear();

    // for(int val : vec){
    //     cout<< val << " ";
    // }
    // cout<<endl;
    
    // // cout<<"size : " << vec.size()<<endl;
    // // cout<<"cap : " <<vec.capacity()<<endl;

    // cout<<"is empty : "<<vec.empty() <<endl;

                          //Iterators

    // vector<int>vec = {1,2,3,4,5};
    
    // cout<<"vec.begin() : "<<*(vec.begin())<<endl;
    // cout<<"vec.end() : "<<*(vec.end())<<endl;


    // vector<int>vec = {1,2,3,4,5};
    
    // vector<int>::iterator it;

    // for(it=vec.begin() ; it != vec.end() ; it++){
    //     cout<<*(it)<<" ";
    // }

    // vector<int>::reverse_iterator it;

    // for(it=vec.rbegin() ; it != vec.rend() ; it++){
    //     cout<<*(it)<<" ";
    // }

    // for(vector<int>::reverse_iterator it=vec.rbegin() ; it != vec.rend() ; it++){
    //     cout<<*(it)<<" ";
    // }
    
    // for(auto it=vec.rbegin() ; it != vec.rend() ; it++){
    //     cout<<*(it)<<" ";
    // }

       
                                          // List

    // list<int> l;
    
    // l.push_back(1);
    // l.push_back(2);
    // l.push_front(3);
    // l.push_front(5);

    // l.pop_back();
    // l.pop_front();

    // for(int val : l){
    //     cout<< val << " ";
    // }
    // cout<<endl;


    // list<int> l={1,2,3,4,5};

    // for(int val : l){
    //     cout<<val<<" ";
    // }

                                              // Deque

    // deque<int> d={1,2,3,4,5};

    // for(int val : d){
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    
    // cout<<d[2]<<endl;//canMerge get random access

    // list<int> l={1,2,3,4,5};

    // for(int val : l){
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    
    // cout<<l[2]<<endl;//cant get random access

                                           // Pair

    // pair <int,int> p = {1,5};

    // cout<< p.first << endl;
    // cout << p.second << endl;

     // pair <int,int> p = {1,5};

    // pair <string , int > p = {"Jahid", 5};//its not necessary pair two be the same value
    // cout<< p.first << endl;
    // cout << p.second << endl;

    // pair <int,pair<char,int>> p ={1,{'a',3}};

    // cout << p.first << endl;
    // cout<< p.second.first << endl;
    // cout << p.second.second << endl;

    // vector<pair<int,int>> vec ={{1,2} , {2,3} , {3,4}};
    

    // vec.push_back({4,5});//insert
    // vec.emplace_back(4,5);//in place object create && faster than push_back

    // for(pair<int,int>p : vec){ // we can use auto instead of pair<int,int>
    //     cout<<p.first<< " " <<p.second<<endl;
    // }

                                              // Stack

    // stack<int>s;

    // s.push(1);
    // s.push(2);
    // s.push(3);
    
    // cout<<"top = "<<s.top()<<endl;

    // while(!s.empty()){
    // cout<<s.top()<<" ";
    // s.pop();
    // }
    // cout<<endl;

    // stack<int>s;

    // s.push(1);
    // s.push(2);
    // s.push(3);

    // stack<int>s2;
    
    // s2.swap(s);

    // cout<<"s size : "<<s.size()<<endl;//0
    // cout<<"s2 size : "<<s2.size()<<endl;//3
     
                                       // Queue

    // queue<int>q;

    // q.push(1);
    // q.push(2);
    // q.push(3);

    // while(!q.empty()){
    //     cout<< q.front()<<" ";
    //     q.pop();
    // }
    // cout<<endl;

    // priority_queue<int>q;

    // q.push(5);
    // q.push(3);
    // q.push(10);
    // q.push(4);

    // while(!q.empty()){
    //     cout<< q.top()<<" ";
    //     q.pop();
    // }
    // cout<<endl;

    // priority_queue<int,vector<int>,greater<int>>q;//for printing in reverse order

    // q.push(5);
    // q.push(3);
    // q.push(10);
    // q.push(4);

    // while(!q.empty()){
    //     cout<< q.top()<<" ";
    //     q.pop();
    // }
    // cout<<endl;



                                      //map

    // map<string ,int> m;

    // m["tv"]=50;
    // m["laptop"]=100;
    // m["headphones"]=50;
    // m["tablet"]=120;
    // m["watch"]=50;

    // m.erase("tv");

    // m.insert({"camera" , 25});// m.emplace("camera",25);
    // for(auto p : m){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    // // cout<<"count = "<<m.count("laptop")<<endl; //how many keys exist in map whose value are laptop
    // // cout<<"count = "<<m["laptop"]<<endl; //value of key


    // if(m.find("camera") != m.end()){
    //     cout<<"found\n";
    // }else
    // {
    //     cout<<"not found\n";
    // }
    


                                             // Other maps
                                             
    // map<string,int>m;

    // m.emplace("tv",100);
    // m.emplace("tv",100);
    // m.emplace("tv",100);
    // m.emplace("tv",100);

    // for(auto p : m){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    // multimap<string,int>m;

    // m.emplace("tv",100);
    // m.emplace("tv",100);
    // m.emplace("tv",100);
    // m.emplace("tv",100);

    // // m.erase("tv");
    // m.erase(m.find("tv"));//if we want to delete only one 
    // for(auto p : m){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }


    // unordered_map<string,int>m;

    // m.emplace("tv",100);
    // m.emplace("laptop",100);
    // m.emplace("fridge",100);
    // m.emplace("watch",100);

    // for(auto p : m){
    //       cout<<p.first<<" "<<p.second<<endl;
    // }



                                         //Set


    // set<int>s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);
 
    // s.insert(1);
    // s.insert(2);
    // s.insert(3);

    // cout<<s.size()<<endl;

    // for(auto val : s){
    //     cout<<val<<" ";
    // }
    
    // set<int>s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5); 
    // s.insert(6);

    // cout<<"lower bound = "<<*(s.lower_bound(4)) <<endl;//4
    
    // set<int>s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(5); 
    // s.insert(6);

    // cout<<"lower bound = "<<*(s.lower_bound(4)) <<endl;//5
    
    // set<int>s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);

    // cout<<"lower bound = "<<*(s.lower_bound(4)) <<endl;//s.end()--0


    // set<int>s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);
  
    // cout<<"lower bound = "<<*(s.lower_bound(4)) <<endl;
    // cout<<"upper bound = "<<*(s.upper_bound(4)) <<endl;

                                    //Other sets

    
    // multiset<int>s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);                                        

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);

    // for(auto val : s){
    //     cout<<val<<" ";
    // }
    // cout<<endl;

    // unordered_set<int>s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);                                        

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);

    // for(auto val : s){
    //     cout<<val<<" ";
    // }
    // cout<<endl;

                                 //Algorithms


    // int arr[5]={3,5,1,8,2};

    // sort(arr,arr+5);

    // for(int val : arr){
    //     cout<<val<<" ";
    // }

    // vector<int>vec={3,5,1,8,2};

    // // sort(vec.begin(),vec.end());
    // sort(vec.begin(),vec.end(),greater<int>());// for descending order

    // for(int val : vec){
    //     cout<<val<<" ";
    // }

    // vector<pair<int , int >> vec ={{3,1},{2,1},{7,1},{5,2}};

    // sort(vec.begin(),vec.end(),comparator);

    // for(auto p : vec){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    // vector<int>vec={1,2,3,4,5};

    // // reverse(vec.begin(),vec.end());

    // reverse(vec.begin()+1,vec.begin()+3);

    // for(int val : vec){
    //     cout<<val<<" ";
    // }


    // string s="bac";

    // // next_permutation(s.begin(),s.end());
    // prev_permutation(s.begin(),s.end());

    // cout<<s<<endl;

    // cout<<max(4,5)<<" "<<min(6,10)<<endl;

    // int a=5,b=10;

    // swap(a,b);
    // cout<<"a = "<<a<<" b = "<<b<<endl;

    // vector<int>vec={1,2,3,4,5};

    // cout<<*(max_element(vec.begin(),vec.end()))<<endl;;
    // cout<<*(min_element(vec.begin(),vec.end()))<<endl;

    // cout<<binary_search(vec.begin(),vec.end(),4)<<endl;

    int n=15;
    long int n2=15;
    long long int n3=15;


    cout<<__builtin_popcount(n)<<endl;
    cout<<__builtin_popcountl(n2)<<endl;
    cout<<__builtin_popcountll(n3)<<endl;

    return 0;
}