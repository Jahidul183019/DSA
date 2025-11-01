#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
    Node* head;

public:
    Stack() {
        head = NULL;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    int pop() {
        if (empty()) {
            cout << "Stack is empty, cannot pop!" << endl;
            return -1;
        }
        Node* temp = head;
        int ans = temp->data;
        head = head->next;
        delete temp;
        return ans;
    }

    int top() {
        if (empty()) {
            cout << "Stack is empty, no top element!" << endl;
            return -1;
        }
        return head->data;
    }

    bool empty() {
        return head == NULL;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                cout << "Popped value: " << s.pop() << endl;
                break;
            case 3:
                cout << "Top value: " << s.top() << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
