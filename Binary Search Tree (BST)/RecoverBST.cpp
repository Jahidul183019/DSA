//Leetcode 99

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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;

    void inorder(TreeNode* root){//TC : O(n) & SC : O(n)
        if(root==NULL){
            return;
        }

        inorder(root->left);
        
        if(prev != NULL && prev->val > root->val){
            if(first==NULL){
                first=prev;
            }
            sec=root;
        }
        prev=root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        int temp=first->val;
        first->val=sec->val;
        sec->val=temp;
    }
};

// For SC : O(1)

class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void recoverTree(TreeNode* root) { // TC: O(n)
        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left == NULL) {
                // detect violation
                if (prev != NULL && prev->val > curr->val) {
                    if (first == NULL) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }

            else {
                // find inorder predecessor (IP)
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    IP->right = curr; // create thread
                    curr = curr->left;
                } 
                else {
                    IP->right = NULL;  // destroy thread

                    // detect violation
                    if (prev != NULL && prev->val > curr->val) {
                        if (first == NULL) first = prev;
                        second = curr;
                    }
                    prev = curr;

                    curr = curr->right;
                }
            }
        }

        // swap the values of the two incorrect nodes
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};