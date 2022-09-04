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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        TreeNode *root = new TreeNode(preorder[0]);
        // if (preorder.size() == 1 && inorder.size() == 1)
        //     return root;
        
        
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int left_size = it - inorder.begin();
        if ( left_size > 0) {
            // nonempty left tree
            vector<int> left_preorder(preorder.begin() +1, preorder.begin()+1+left_size);
            vector<int> left_inorder(inorder.begin(), it);
            
            root->left = buildTree(left_preorder, left_inorder);
        }
        
        int right_size = inorder.end() - it - 1;
        if (right_size > 0) {
            // nonempty right tree
            
            vector<int> right_preorder(preorder.begin()+1+left_size, preorder.end());
            vector<int> right_inorder(it+1, inorder.end());
            root->right = buildTree(right_preorder, right_inorder);
        }
        
        return root;
    }
};