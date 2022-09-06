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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if (root == nullptr) return nullptr;
        
        // root and it's right children is out of the interval
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        // root and it's left children is out of the interval
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        
        // root is in the inverval
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};