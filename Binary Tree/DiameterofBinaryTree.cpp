//Leetcode 543

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*

//TC:O(n)
class Solution {
public:
    int height(TreeNode* root){//O(n)
        if(root==NULL) return 0;

        int leftHt=height(root->left);
        int rightHt=height(root->right);

        return max(leftHt,rightHt)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        int leftDiam=diameterOfBinaryTree(root->left);
        int rightDiam=diameterOfBinaryTree(root->right);
        int currDiam=height(root->left)+height(root->right);

        return max(currDiam,max(leftDiam,rightDiam));
    }
};
*/

//Optimize Code : TC:O(n)

class Solution {
public:
    int ans=0;
    int height(TreeNode* root){//O(n)
        if(root==NULL) return 0;

        int leftHt=height(root->left);
        int rightHt=height(root->right);
        
        ans=max(ans,leftHt+rightHt);//current diameter of root node

        return max(leftHt,rightHt)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return ans;
    }
};