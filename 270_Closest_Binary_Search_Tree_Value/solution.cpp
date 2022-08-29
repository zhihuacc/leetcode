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
    int closestValue(TreeNode* root, double target) {
        
        if (root == nullptr)
            return -1;
        
        int closest = root->val;
        TreeNode *curr = root;
        while (curr != nullptr) {
                
            if (std::abs(curr->val - target) < std::abs(closest - target))
                closest = curr->val;
            
            if (target < curr->val)
                curr = curr->left;
            else if (target > curr->val)
                curr = curr->right;
            else
                return target;
            
        }
        
        return closest;
    }
};