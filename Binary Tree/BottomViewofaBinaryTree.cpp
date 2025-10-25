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

// Bottom View of Binary Tree
// TC: O(n log n)
void bottomView(Node* root){
    if(root == NULL) return;

    queue<pair<Node*, int>> q;   // (node, horizontal distance)
    map<int, int> m;             // <HD, Node->data>

    q.push({root, 0});

    while(!q.empty()){
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        // For bottom view, always update the map
        m[hd] = curr->data;

        if(curr->left != NULL){
            q.push({curr->left, hd - 1});
        }
        if(curr->right != NULL){
            q.push({curr->right, hd + 1});
        }
    }

    // Print bottom view
    for(auto it : m){
        cout << it.second << " ";
    }
    cout << endl;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=buildTree(preorder);

    bottomView(root);
    

    return 0;
}