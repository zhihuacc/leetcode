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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            
            p1 = p1 != nullptr ? p1->next : headB;
            p2 = p2 != nullptr ? p2->next : headA;
        }
        
        return p1;
    }
};

// WARN: another idea is to count the nodes of the two lists, 
//   and iterate from the begining of the longer one by the diff of the two lengths.
//   Unluckily this simple idea can't detect whether the two lists intersect or not.