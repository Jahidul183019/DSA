#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node* prev;
	
	Node(int val){
		data=val;
		next=prev=NULL;
	}
};

class DoublyList{
	Node* head;
	Node* tail;
	
	public:
	DoublyList(){
		head=tail=NULL;
	}

	//  Push Front
	void push_front(int val){
		Node* newNode= new Node(val);
	
		if(head==NULL){
			head=tail=newNode;
		}
		else{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}
	}

	//  Push Back
	void push_back(int val){
		Node* newNode=new Node(val);
	
		if(head==NULL){
			head=tail=newNode;
		}
		else{
			newNode->prev=tail;
			tail->next=newNode;
			tail=newNode;
		}
	}

	//  Pop Front
	void pop_front(){
		if(head==NULL){
			cout<<"DLL is empty\n";
			return;
		}
	
		Node* temp=head;
		head=head->next;
	
		if(head!=NULL){
			head->prev=NULL;
		}
		else{
			tail=NULL;
		}
	
		temp->next=NULL;
		delete temp;
	}

	//  Pop Back
	void pop_back(){
		if(head==NULL){
			cout<<"DLL is empty\n";
			return;
		}

		Node* temp=tail;
		tail=tail->prev;
	
		if(tail!=NULL){
			tail->next=NULL;
		}
		else{
			head=NULL;
		}
	
		temp->prev=NULL;
		delete temp;
	}

	//  Print
	void print(){
		Node* temp=head;
	
		while(temp!=NULL){
			cout<<temp->data<<"<=>";
			temp=temp->next;
		}
	
		cout<<"NULL\n";
	}
};

int main(){
	DoublyList dll;
	
	dll.push_front(1);
	dll.push_front(2);
	dll.push_front(3);
	dll.print();
	
	dll.push_back(1);
	dll.push_back(2);
	dll.push_back(3);
	dll.print();
	
	dll.pop_front();
	dll.pop_front();
	dll.print();
	
	dll.pop_back();
	dll.pop_back();
	dll.print();
	
	return 0;
}