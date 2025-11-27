//Leetcode 235
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {//TC : O(height) and for Balanced BST TC : O(logn)
        if(root==NULL) return NULL;

        if(root->val > p->val && root->val > q->val){//left subtree
            return lowestCommonAncestor(root->left,p,q);
        }else  if(root->val < p->val && root->val < q->val){//right subtree
            return lowestCommonAncestor(root->right,p,q);
        }else{
            return root;
        }
    }
};