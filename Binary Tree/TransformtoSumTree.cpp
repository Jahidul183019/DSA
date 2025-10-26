#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

static int idx=-1;

Node* buildTree(vector<int>preorder){//TC:O(n)
   idx++;
   if(preorder[idx]==-1){
    return NULL;
   }

   Node* root=new Node(preorder[idx]);
   root->left=buildTree(preorder);//LEFT
   root->right=buildTree(preorder);//RIGHT

   return root;
}

//preorder Traversal

void preOrder(Node* root){//TC:O(n)
  if(root==NULL){
    return;
  }

  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

//Transform to Sum Tree
int sumTree(Node* root){//TC:O(n)
    if(root==NULL) return 0;

    int leftSum=sumTree(root->left);
    int rightSum=sumTree(root->right);

    root->data+=leftSum+rightSum;

    return root->data;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=buildTree(preorder);

    cout<<"Before Conversion : ";
    preOrder(root);
    cout<<endl;

    sumTree(root);

    cout<<"After Conversion : ";
    preOrder(root);
    cout<<endl;
    

    return 0;
}