#include<iostream>
#include<vector>
#include<queue>
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

//inOrder Traversal

void inOrder(Node* root){//TC:O(n)
  if(root==NULL){
    return;
  }

  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

//postOrder Traversal

void postOrder(Node* root){//TC:O(n)
  if(root==NULL){
    return;
  }

  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";

}

//Level Order Traversal

// void levelOrder(Node* root){
//   queue<Node*>q;

//   q.push(root);

//   while(q.size()>0){
//     Node* curr=q.front();
//     q.pop();

//     cout<<curr->data<<" ";

//     if(curr->left!=NULL){
//       q.push(curr->left);
//     }

//     if(curr->right!=NULL){
//       q.push(curr->right);
//     }
//   }
//   cout<<endl;
// }

//if we want to print level wise 

void levelOrder(Node* root){
  queue<Node*>q;

  q.push(root);
  q.push(NULL);


  while(q.size()>0){
    Node* curr=q.front();
    q.pop();

      if(curr==NULL){
    if(!q.empty()){
      cout<<endl;
      q.push(NULL);
      continue;

    }
    else{
      break;
    }
  }

    cout<<curr->data<<" ";

    if(curr->left!=NULL){
      q.push(curr->left);
    }

    if(curr->right!=NULL){
      q.push(curr->right);
    }
  }
  cout<<endl;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=buildTree(preorder);

    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;

    // preOrder(root);
    //cout<<endl

    // inOrder(root);
    // cout<<endl;
    
    // postOrder(root);
    // cout<<endl;
    
    levelOrder(root);
    

    return 0;
}