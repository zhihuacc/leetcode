class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        
        // WARN: different from 141. Linked List Cycle
        //   Ensure to start at the same node, otherwise, the second while-loop will not end, 
        //   , while the two pointers no need to start at the same node in 141.
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            
            fast = fast->next->next;
            slow = slow->next;
            
            if (slow == fast) {
                break;
            }
        }
        
        if (slow != fast) {
            return nullptr;
        }
        
        // Two pointers should meet at the start of cycle.
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};

// Fast slow pointer
// https://leetcode.com/problems/linked-list-cycle-ii/