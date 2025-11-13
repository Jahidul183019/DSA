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

   void display(){
    if(heap_size==0){
        cout<<"Heap is empty"<<endl;
        return;
    }

    cout<<"current heap : ";
    for(int i=0;i<heap_size;i++){
        cout<<harr[i]<<" ";
    }
        cout<<endl;
   }

   int getMin(){
    if(heap_size>0){
        return harr[0];
    }
    else{
        return INT_MAX;
    }
   }
};
int main(){
    int cap;
    cout << "Enter capacity of heap: ";
    cin >> cap;
    MinHeap h(cap);

    int choice, key, index, new_val;

    do
    {
        cout << "\n==== MIN HEAP MENU ====\n";
        cout << "1. Insert Key\n";
        cout << "2. Extract Min\n";
        cout << "3. Get Min\n";
        cout << "4. Delete Key (by index)\n";
        cout << "5. Decrease Key (by index)\n";
        cout << "6. Display Heap\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> key;
            h.insertKey(key);
            break;

        case 2:
            key = h.extractMin();
            if (key == INT_MAX)
                cout << "Heap is empty!\n";
            else
                cout << "Extracted Min: " << key << endl;
            break;

        case 3:
            key = h.getMin();
            if (key == INT_MAX)
                cout << "Heap is empty!\n";
            else
                cout << "Minimum element: " << key << endl;
            break;

        case 4:
            cout << "Enter index to delete: ";
            cin >> index;
            h.deleteKey(index);
            break;

        case 5:
            cout << "Enter index to decrease: ";
            cin >> index;
            cout << "Enter new value: ";
            cin >> new_val;
            h.decreaseKey(index, new_val);
            break;

        case 6:
            h.display();
            break;

        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}