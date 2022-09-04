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
    
    TreeNode *builder(vector<int> &preorder, int &idx, int low_bound, int high_bound) {
        
        if (idx == preorder.size())
            return nullptr;
        
        int val = preorder[idx];
        TreeNode *root = nullptr;
        if (val <= low_bound || val >= high_bound) {
            // if preorder[idx] is not a valid node of left or right tree.
            return nullptr;
        } else {
            root = new TreeNode(val);
        }
        
        idx++;
        // Check if preorder[idx] is a left node
        // If it's a left node, idx will be moved to next val.
        // If it's not a left node, idx will not be changed.
        root->left = builder(preorder, idx, low_bound, val);
        // Check if preorder[idx] is a right node.
        root->right = builder(preorder, idx, val, high_bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int idx = 0;
        return builder(preorder, idx, INT_MIN, INT_MAX);
    }
};