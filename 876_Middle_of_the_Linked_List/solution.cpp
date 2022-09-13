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
    ListNode* middleNode(ListNode* head) {
        
        ListNode *slow = head, *fast = head;
        // if need first mid noe, then while-condition and the below if-condition
        //   need be changed to fast->next != nullptr
        while (fast != nullptr) {
            
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            } else {
                break;
            }
        }
        
        return slow;
    }
};