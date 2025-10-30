// LeetCode 21: Merge Two Sorted Lists
// Time Complexity: O(n + m)   // We traverse each list once
// Space Complexity: O(n + m)  // Recursion stack uses space

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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        // If one of the lists is empty, return the other list
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }

        // Compare values and recursively build the sorted list
        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } 
        else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};
