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
    
    bool validate_and_sum(TreeNode *root, int &min_val, int &max_val, int &sum, int &max_sum) {
        
        if (root == nullptr) {
            max_sum = 0;
            sum = 0;
            min_val = INT_MAX;
            max_val = INT_MIN;
            return true;
        }
        
        int val = root->val;
        
        int left_min, left_max, left_sum, left_max_sum, right_min, right_max, right_sum, right_max_sum;
        bool left_is_bst = validate_and_sum(root->left, left_min, left_max, left_sum, left_max_sum);
        bool right_is_bst = validate_and_sum(root->right, right_min, right_max, right_sum, right_max_sum);
        
        
        // This subtree is bst
        if (left_is_bst && right_is_bst && val > left_max && val < right_min) {
            // WARN: can't use min_val = left_min because left_min may be INT_MAX
            min_val = std::min(left_min, val);
            max_val = std::max(right_max, val);
            sum = val + left_sum + right_sum;
            // WARN: because nodes may be negative, so the max sum may be a smaller BST in a bigger BST
            // In case [4,8,null,6,1,9,null,-5,4,null,null,null,-3,null,10], 
            //   the max-sum BST is rooted at 4, and the max sum is 14 with 4+10. 
            //   But the subtree rooted at 1 is a bigger BST.
            max_sum = std::max(std::max(left_max_sum, right_max_sum), sum);
            return true;
        }
        
        max_sum = std::max(left_max_sum, right_max_sum);
        return false;
    }
public:
    int maxSumBST(TreeNode* root) {
        
        int dummy0, dummy1, dummy2,  max_sum = 0;
        validate_and_sum(root, dummy0, dummy1, dummy2, max_sum);
        return max_sum;
    }
};