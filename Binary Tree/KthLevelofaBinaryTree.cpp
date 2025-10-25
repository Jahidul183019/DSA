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

//Kth Level of a Binary Tree
//TC:O(n)
void KthLevel(Node* root,int K){
    if(root == NULL){
        return;
    }

    if(K==1){
        cout<<root->data<<" ";
        return;
    }

    KthLevel(root->left,K-1);
    KthLevel(root->right,K-1);
}
int main(){
    vector<int>preorder={1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=buildTree(preorder);

    KthLevel(root,3);
    

    return 0;
}