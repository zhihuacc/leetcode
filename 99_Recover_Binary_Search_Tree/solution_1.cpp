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
    
    TreeNode *prev;
    TreeNode *x;
    TreeNode *y;
    void dfs(TreeNode *root) {
        
        if (root == nullptr)
           return;
        
        dfs(root->left);
        // WARN: If there are more than two nodes that are swapped, this logic of finding x and y won't work.
        if (prev != nullptr && root->val < prev->val) {
            
            if (x == nullptr) {
                // Find the first swaped pair. Take prev as x.
                // Continue checking following nodes for the second swaped pair.
                x = prev;
                y = root;
            } else {
                // Find the second swaped pair. Take root as y.
                // No need to check following nodes
                y = root;
                return;
            }
        }
        // Take root as prev and continue checking
        prev = root;
        dfs(root->right);
    }

public:
    
    void recoverTree(TreeNode* root) {
        prev = nullptr;
        x = nullptr;
        y = nullptr;
        
        dfs(root);
        std::swap(x->val, y->val);
    }
};