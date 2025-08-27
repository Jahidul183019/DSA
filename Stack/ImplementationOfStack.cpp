// Using Vector
/* 
#include <iostream>
#include <vector>

using namespace std;

class Stack {
    vector<int>v;

public:

    void push(int val){//O(1)
        v.push_back(val);
    }

    void pop(){//O(1)
        v.pop_back();
    }

    int top(){//O(1)
        return v[v.size()-1];
    }

    bool empty(){
        return v.size() == 0;
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;//30 20 10

    return 0;

}
*/

//Using Linked List

/*
#include <iostream>
#include <vector>
#include <list>

using namespace std;
class Stack {
    list<int>ll;

public:

    void push(int val){//O(1)
        ll.push_front(val);
    }

    void pop(){//O(1)
        ll.pop_front();
    }

    int top(){//O(1)
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;//30 20 10

    return 0;
}
*/

// Using C++ STL

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

int main(){
    stack <int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;//30 20 10

    return 0;
}