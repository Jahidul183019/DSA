#include <iostream>

using namespace std;

class CircularQueue{
    int* arr;
    int currSize,cap;
    int f,r;

    public:
    CircularQueue(int size){
        cap=size;
        arr = new int [cap];
        currSize=0;
        f=0;
        r=-1;
    }

    void push(int data){//O(1)
        if(currSize==cap){
            cout<<"CQ is FULL\n";
            return;
        }
        r = (r+1)%cap;
        arr[r]=data;
        currSize++;
    }

    void pop(){//O(1)
        if(empty()){
            cout<<"CQ is EMPTY\n";
            return;
        }
        f=(f+1)%cap;
        currSize--;
    }

    int front(){//O(1)
        if(empty()){
            cout<<"CQ is EMPTY\n";
            return -1;
        }
        return arr[f];
    }
    
    bool empty(){//O(1)
        return currSize==0;
    }

    void PrintArr(){
        for(int i=0;i<cap;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
  CircularQueue cq(3);

  cq.push(1);
  cq.push(2);
  cq.push(3);
  
  //cq.push(4);

  cq.pop();

  cq.push(4);

  cq.PrintArr();//4 2 3 

  while(!cq.empty()){
    cout<<cq.front()<<" "; // 2 3 4
    cq.pop();
  }
  cout<<endl;

  return 0;
}