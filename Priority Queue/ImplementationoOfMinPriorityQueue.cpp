#include<iostream>
#include<climits>

using namespace std;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

class MinHeap{
   int *harr;
   int capacity;
   int heap_size;

   public:
   MinHeap(int cap){
    harr=new int[cap];
    capacity=cap;
    heap_size=0;
   }
   
   int parent(int i){
    return (i-1)/2;
   }

   int left(int i){
    return (2*i+1);
   }

   int right(int i){
    return (2*i+2);
   }
   void insertKey(int k){
    if(heap_size==capacity){
        cout<<"Heap Overflow!"<<endl;
        return;
    }

    int i=heap_size++;
    harr[i]=k;

    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i=parent(i);
    }
   }

   void decreaseKey(int i,int newVal){
    if(i>=heap_size){
        cout<<"Invalid Index"<<endl;
        return;
    }

    harr[i]=newVal;
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i=parent(i);
    }
   }

   void MinHeapify(int i){
    int l=left(i);
    int r=right(i);
    int smallest=i;

    if(l<heap_size && harr[l]<harr[smallest]){
        smallest=l;
    }
    if(r<heap_size && harr[r]<harr[smallest]){
        smallest=r;
    }
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
 }
   int extractMin(){
    if(heap_size<=0) return INT_MAX;
    if(heap_size==1){
        heap_size--;
        return harr[0];
    }
    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
   }

   void deleteKey(int k){
    if(k>=heap_size){
        cout<<"Invalid Index"<<endl;
        return;
    }
    decreaseKey(k,INT_MIN);
    extractMin();
   }

   int getMin(){
    if(heap_size>0){
        return harr[0];
    }
    else{
        return INT_MAX;
    }
   }

   int size(){
    return heap_size;
   }

   bool empty(){
    return heap_size==0;
   }

   void display(){
    if(heap_size==0){
        cout<<"Priority Queue is empty"<<endl;
        return;
    }
    cout<<"Current Elements : ";
    for(int i=0;i<heap_size;i++){
        cout<<harr[i]<<" ";
    }
    cout<<endl;
   }
};

class PriorityQueue{
    MinHeap heap;

    public:
    PriorityQueue(int cap) : heap(cap) {}

    void push(int val){
        heap.insertKey(val);
    }

    void pop(){
        int x=heap.extractMin();
        if(x==INT_MAX){
            cout<<"Priority Queue is empty"<<endl;
        }else{
            cout<<"Removed Element : "<<x<<endl;
        }
    }

    int top(){
        int x=heap.getMin();
        if(x==INT_MAX){
            cout<<"Priority Queue is empty"<<endl;
            return -1;
        }
        return x;
    }

    void display(){
        heap.display();
    }

    bool empty(){
        return heap.empty();
    }
    int size(){
        return heap.size();
    }
};

int main(){
int cap;
    cout<<"Enter capacity of Priority Queue: ";
    cin>>cap;

    PriorityQueue pq(cap);  

    int choice, val;

    do{
        cout<<"\n==== PRIORITY QUEUE MENU ====\n"; 
        cout<<"1. Push (Insert)\n";
        cout<<"2. Pop (Remove Min)\n";
        cout<<"3. Top (Get Min)\n";
        cout<<"4. Display all elements\n";  
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value to push: ";
                cin>>val;
                pq.push(val);
                break;
            case 2:
                pq.pop();
                break;
            case 3:
                val=pq.top();
                if(val!=-1) cout<<"Top element: "<<val<<endl;
                break;
            case 4:   
                pq.display();
                break;
            case 0:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice! Try again.\n";
        }

    }while(choice!=0);

    return 0;
}