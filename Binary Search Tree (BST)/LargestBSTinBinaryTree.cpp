#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* insert(Node* root,int val){
  if(root==NULL){
    return new Node(val);
  }

  if(val<root->data){
    root->left=insert(root->left,val);
  }else{
    root->right=insert(root->right,val);
  }
  return root;
}

Node* buildBST(vector<int>arr){
    Node* root=NULL;

    for(int val : arr){
        root=insert(root,val);
    }
    return root;
}

// Find the size of largest BST in Binary Tree

class Info{
    public:
      int min,max,sz;

      Info(int mi,int ma,int size){
        min=mi;
        max=ma;
        sz=size;
      }
};

Info helper(Node* root){// TC : O(n)
    if(root==NULL){
        return Info(INT_MAX,INT_MIN,0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data>left.max && root->data<right.min){
        int currMin=min(root->data,left.min);
        int currMax=max(root->data,right.max);
        int currSz=left.sz+right.sz+1;

        return Info(currMin,currMax,currSz);
    }
    return Info(INT_MIN,INT_MAX,max(left.sz,right.sz));
}

int largestBSTinBT(Node* root){
    Info info=helper(root);
    return info.sz;//max BST size
}

int main(){
    Node* root = new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);

    root->left->left=new Node(1);
    root->left->right=new Node(8);
    root->right->right=new Node(7);

    cout<<largestBSTinBT(root)<<endl;

    return 0;
}