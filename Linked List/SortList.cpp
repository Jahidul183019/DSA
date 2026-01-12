// Leetcode 148

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
     ListNode* slow=head;
     ListNode* fast=head;
     ListNode* prev = NULL;

     while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast= fast->next->next;
     }

     if(prev){
     prev->next=NULL;
     }
     
     if (head == slow) return head;
     ListNode* h1=sortList(head);
     ListNode* h2=sortList(slow);

     return merge(h1,h2);
        
    }
    ListNode* merge(ListNode* h1,ListNode* h2){
        if(h1==NULL || h2==NULL){
            return h1==NULL?h2:h1;

        }
        if(h1->val <=h2-> val){
            h1->next=merge(h1->next,h2);
            return h1;
        }else{
            h2->next=merge(h1,h2->next);
            return h2;
        }
    }
};
