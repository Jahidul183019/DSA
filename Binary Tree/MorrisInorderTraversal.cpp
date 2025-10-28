//Leetcode 94

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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {// TC:O(n)
        vector<int>ans;
        TreeNode* curr=root;

        while(curr!=NULL){
            if(curr->left==NULL){
               ans.push_back(curr->val);
               curr=curr->right;
            }else{
                //find the IP
                TreeNode* IP=curr->left;
                while(IP->right!=NULL && IP->right!=curr){
                    IP=IP->right;
                }
                if(IP->right==NULL){
                    IP->right=curr;//Create
                    curr=curr->left;
                }else{
                    IP->right=NULL;//Destroy
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};