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
    
    
    int validateBST(TreeNode *root, int &max_val, int &min_val, int &bst_nodes) {
        
        if (root == nullptr) {
            max_val = INT_MIN;
            min_val = INT_MAX;
            bst_nodes = 0;
            return 1;
        }
        
        int left_bst = 1, right_bst = 1, cur_bst = 0;
        int left_max = INT_MIN, left_min = INT_MAX, right_max = INT_MIN, right_min = INT_MAX;
        int left_nodes = 0, right_nodes = 0;
        if (root->left != nullptr) {
            left_bst = validateBST(root->left, left_max, left_min, left_nodes);
        }
        
        if (root->right != nullptr) {
            right_bst = validateBST(root->right, right_max, right_min, right_nodes);
        }
        
        max_val = INT_MIN;
        max_val = max(root->val,max(right_max, max(max_val, left_max)));
            
        min_val = INT_MAX;
        min_val = min(root->val,min(right_min, min(min_val, left_min)));
        
        
        if (left_max < root->val && right_min > root->val)
            cur_bst = 1;
        
        cur_bst = left_bst && right_bst && cur_bst;
        
        if (cur_bst == 1) {
            
            bst_nodes = left_nodes + right_nodes + 1;
        } else {
            bst_nodes = max(left_nodes, right_nodes);
        }
        
        return cur_bst;
    }
    
public:
    int largestBSTSubtree(TreeNode* root) {
        int max_val = INT_MIN, min_val = INT_MAX, bst_nodes = 0;
        
        validateBST(root, max_val, min_val, bst_nodes);
        
        return bst_nodes;
    }
};