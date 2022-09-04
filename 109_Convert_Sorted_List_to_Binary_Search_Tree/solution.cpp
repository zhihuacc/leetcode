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
    
    ListNode *curr_head;
    
    TreeNode *cvt_to_bst(int left, int right) {
        
        if (left > right)
            return nullptr;
        
        int mid = (left + right) / 2;
        // Construct a bst using (left, mid-1) nodes, and curr_head is pointing to left-th node
        //  before the construction, and to the mid-the node after.
        TreeNode *left_bst = cvt_to_bst(left, mid-1);
        
        TreeNode *root = new TreeNode(curr_head->val);
        root->left = left_bst;
        
        curr_head = curr_head->next;
        // Construct a bst using (mid+1, right) nodes.
        TreeNode *right_bst = cvt_to_bst(mid+1, right);
        root->right = right_bst;
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        int len = 0;
        for (auto curr = head; curr != nullptr; curr = curr->next, len++);
        
        if (len == 0)
            return nullptr;
        
        curr_head = head;
        return cvt_to_bst(0, len-1);
    }
};