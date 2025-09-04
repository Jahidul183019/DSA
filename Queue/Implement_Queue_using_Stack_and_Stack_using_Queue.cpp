                           // Implementation of Stack Using Queue
/*
#include <iostream>
#include <queue>
using namespace std;

//Leetcode 225
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {//O(n)
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {//O(1)
        int ans=q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {//O(1)
        return q1.front();
    }
    
    bool empty() {//O(1)
        return q1.empty();
    }
};

int main() {
    MyStack st;
    int choice, val;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Check Empty\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                st.push(val);
                cout << val << " pushed into stack.\n";
                break;

            case 2:
                if(!st.empty()) {
                    cout << "Popped: " << st.pop() << endl;
                } else {
                    cout << "Stack is empty!\n";
                }
                break;

            case 3:
                if(!st.empty()) {
                    cout << "Top element: " << st.top() << endl;
                } else {
                    cout << "Stack is empty!\n";
                }
                break;

            case 4:
                cout << (st.empty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 5);

    return 0;
}

*/
                              //// Implementation of Queue Using Stack

#include <iostream>
#include <stack>
using namespace std;

//Leetcode 232
class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {//O(n)
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {//O(1)
        int ans=s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {//O(1)
        return s1.top();
    }
    
    bool empty() {//O(1)
        return s1.empty();
    }
};

int main() {
    MyQueue q;
    int choice, val;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue (push)\n";
        cout << "2. Dequeue (pop)\n";
        cout << "3. Front (peek)\n";
        cout << "4. Check Empty\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.push(val);
                cout << val << " added to queue.\n";
                break;

            case 2:
                if(!q.empty()) {
                    cout << "Dequeued: " << q.pop() << endl;
                } else {
                    cout << "Queue is empty!\n";
                }
                break;

            case 3:
                if(!q.empty()) {
                    cout << "Front element: " << q.peek() << endl;
                } else {
                    cout << "Queue is empty!\n";
                }
                break;

            case 4:
                cout << (q.empty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}
