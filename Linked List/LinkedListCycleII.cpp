// LeetCode 142: Linked List Cycle II
// Time Complexity: O(n)     // We traverse the list at most twice
// Space Complexity: O(1)    // No extra data structure used (constant space)

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool isCycle = false;

        // First step: detect if a cycle exists using slow & fast pointers
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;         // moves 1 step
            fast = fast->next->next;   // moves 2 steps

            if(slow == fast){          // cycle detected
                isCycle = true;
                break;
            }
        }

        // If no cycle found, return NULL
        if(!isCycle) return NULL;

        // Second step: find the starting node of the cycle
        slow = head;                   // move slow to head
        while(slow != fast){           // both move 1 step until they meet
            slow = slow->next;
            fast = fast->next;
        }

        return slow;   // this is the node where cycle begins
    }
};
