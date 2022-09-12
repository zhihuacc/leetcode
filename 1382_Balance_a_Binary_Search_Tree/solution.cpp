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
    
    void inorder(TreeNode *root, vector<int> &nodes) {
        
        if (root == nullptr)
            return;
        
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
    
    TreeNode *buildBBST(const vector<int> &nodes, int left, int right) {
        
        if (left > right)
            return nullptr;
        
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nodes[mid]);
        root->left = buildBBST(nodes, left, mid - 1);
        root->right = buildBBST(nodes, mid + 1, right);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> nodes;
        inorder(root, nodes);
        
        return buildBBST(nodes, 0, nodes.size() - 1);
    }
};