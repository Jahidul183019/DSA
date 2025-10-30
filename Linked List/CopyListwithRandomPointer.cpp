// LeetCode 138: Copy List with Random Pointer
// Time Complexity: O(n)       // We traverse the list twice
// Space Complexity: O(n)      // Hash map to store mapping of old -> new nodes

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // If list is empty, return NULL
        if(head == NULL) return NULL;

        // Map to store original node -> copied node mapping
        unordered_map<Node*, Node*> mp;

        // Create the head for new list
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        mp[head] = newHead;

        // First pass: copy 'next' pointers and store mapping
        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            mp[oldTemp] = copyNode;

            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Reset pointers
        oldTemp = head;
        newTemp = newHead;

        // Second pass: set random pointers using the map
        while(oldTemp != NULL){
            newTemp->random = mp[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
