#include<iostream>
#include<climits>


using namespace std;

void swapVal(int& x,int& y){
    int temp=x;
    x=y;
    y=temp;
}
class MaxHeap{
public:
    int* harr;
    int capacity;
    int heap_size;
    
    MaxHeap(int cap){
        heap_size=0;
        capacity=cap;
        harr=new int[cap];
    }

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){ 
        return 2*i+2;
    }
    void insertKey(int k){
        if(heap_size==capacity){
            cout<<"Overflow"<<endl;
            return;
        }

        int i = heap_size;
        harr[i] = k;
        heap_size++;         


        while(i!=0 && harr[parent(i)]<harr[i]){
            swapVal(harr[i],harr[parent(i)]);
            i=parent(i);
        }
    }
    void increaseKey(int i,int newVal){
        harr[i]=newVal;

        while(i!=0 && harr[parent(i)]<harr[i]){
            swapVal(harr[i],harr[parent(i)]);
            i=parent(i);
        }
    }
    int extractMax(){
        if(heap_size==0){
            return INT_MIN;
        }
        if(heap_size==1){
            heap_size--;
            return harr[0];
        }
        int root=harr[0];
        harr[0]=harr[heap_size-1];
        heap_size--;
        MaxHeapify(0);

        return root;
    }
    void deleteKey(int i){
        increaseKey(i,INT_MAX);
        extractMax();
    }
    void MaxHeapify(int i){
        int l=left(i);
        int r=right(i);
        int largest=i;

        if(l<heap_size && harr[largest]<harr[l]){
            largest=l;
        }
        if(r<heap_size && harr[r]>harr[largest]){
            largest=r;
        }

        if(largest!=i){
            swapVal(harr[i],harr[largest]);
            MaxHeapify(largest);
        }
    }
    void display(){
        if(heap_size==0){
            cout<<"Heap is Empty"<<endl;
            return;
        }

        cout<<"Current Heap : ";
        for(int i=0;i<heap_size;i++){
            cout<<harr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int cap;
    cout<<"Enter capacity of MaxHeap : "<<endl;
    cin>>cap;
    MaxHeap h(cap);

    int choice,key,index,newVal;

    do
    {
        cout<<"\n===========MAX HEAP MENU================\n";
        cout<<"1.Insert Key\n";
        cout<<"2.Extract Max\n";
        cout<<"3.Delete Key (by index)\n";
        cout<<"4.Increase Key (by index)\n";
        cout<<"5.Display\n";
        cout<<"6.Exit\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter the value to insert : ";
            cin>>key;
            h.insertKey(key);
            break;
        case 2:
             key=h.extractMax();
             if(key==INT_MIN){
                cout<<"Heap is Empty!\n";
             }else{
                cout<<"Extracted Max : "<<key<<endl;
             }
             break;
        case 3:
            cout<<"Enter index to delete : ";
            cin>>index;
            h.deleteKey(index);
            break;
        case 4:
           cout<<"Enter index to increase: ";
            cin>>index;
            cout<<"Enter new value: ";
            cin>>newVal;
            h.increaseKey(index,newVal); 
            break;
        case 5:
            h.display();
            break;
        case 6:
            cout<<"Exiting program.\n";
            break;
        default:
           cout<<"Invalid choice! Try again.\n";
            break;
        }
    } while (choice!=6);
    
    return 0;
}