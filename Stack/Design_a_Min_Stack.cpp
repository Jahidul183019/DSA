/*
#include <iostream>
#include <stack>
using namespace std;

//Leecode 155
//Time Complexity : O(n)
//Space Complexity : O(2*n)

class MinStack {
public:
    stack<pair<int,int>> s; // val, minVal
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }else{
            int minVal = min(val, s.top().second);
            s.push({val,minVal});
        }
    }
    
    void pop() {
        return s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

int main() {
    MinStack st;
    st.push(5);
    st.push(3);
    st.push(7);
    cout << st.top() << endl;     // 7
    cout << st.getMin() << endl;  // 3
    st.pop();
    cout << st.top() << endl;     // 3
    cout << st.getMin() << endl;  // 3
}
*/

                                //Optimized Approach
#include <iostream>
#include <stack>
using namespace std;

//Leecode 155
//Time Complexity : O(n)
//Space Complexity : O(n)
class MinStack {
public:
    stack<long long>s;
    long long int minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal=val;
        }else{
            if(val<minVal){
                s.push((long long)2*val-minVal);
                minVal=val;
            }else{
                s.push(val);
            }
        }
        
    }
    
    void pop() {
        if(s.top()<minVal){
            minVal=2*minVal-s.top();
        }
        s.pop(); 
    }
    
    int top() {
        if(s.top()<minVal){
            return minVal;
        }
        return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};

int main() {
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout << st.top() << endl; //-3
    cout << st.getMin() << endl; //-3
    st.pop();
    cout << st.top() << endl; //0
    cout << st.getMin() << endl; //-2
}
