// Leetcode 141 | Linked List Cycle
// Time Complexity: O(n)    // We traverse each node at most once with slow & fast pointers
// Space Complexity: O(1)   // Constant extra space (no extra data structures used)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;           // moves 1 step
            fast = fast->next->next;     // moves 2 steps

            if(slow == fast){
                return true; // cycle detected
            }
        }
        return false; // no cycle
    }
};
