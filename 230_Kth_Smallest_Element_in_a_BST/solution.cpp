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
    
    int curr_idx;
    int found_val;
    bool dfs(TreeNode *root, int k) {
        
        if (root == nullptr)
            return false;
        
        bool found = dfs(root->left, k);
        if (found)
            return true;
        
        curr_idx++;
        if (curr_idx == k) {
            found_val = root->val;
            return true;
        }
        
        found = dfs(root->right, k);
        return found;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        
        curr_idx = 0;
        bool found = dfs(root, k);
        if (found)
            return found_val;
        return -1;
    }
};