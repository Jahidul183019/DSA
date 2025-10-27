#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class circularList{
    Node* head;
    Node* tail;
    
    public:
    circularList(){
        head=tail=NULL;
    }

    void insertAtHead(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

    void insertAtTail(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void deleteAtHead(){
        if(head==NULL) return;
        else if(head==tail){//Single Node
            delete head;
            head=tail=NULL;
        }else{//2 or more Node
            Node* temp=head;
            head=head->next;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }
    void deleteAtTail(){
        if(head==NULL) return;
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            Node* temp=tail;
            Node* prev=head;

            while(prev->next!=tail){
                prev=prev->next;
            }
            tail=prev;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }

    void print(){
        if(head==NULL) return;

        cout<<head->data<<"->";
        Node* temp=head->next;

        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};

int main(){
    circularList cll;

    /*
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);

    cll.print();

    cll.deleteAtHead();
    cll.print();

    cll.deleteAtHead();
    cll.print();

    cll.deleteAtHead();
    cll.print();
   */

    cll.insertAtTail(1);
    cll.insertAtTail(2);
    cll.insertAtTail(3);

    cll.print();

    cll.deleteAtTail();
    cll.print();

    cll.deleteAtTail();
    cll.print();

    cll.deleteAtTail();
    cll.print();

    return 0;
}