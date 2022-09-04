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
    
    TreeNode *successor(TreeNode *root, TreeNode *&parent) {
        

        if (root == nullptr || root->right == nullptr) {
            parent = nullptr;
            return nullptr;
        }
        
        parent = root;
        TreeNode *curr = root->right;
        while (curr->left != nullptr) {
            
            parent = curr;
            curr = curr->left;
        }
        return curr;
    }
    
    TreeNode *predecessor(TreeNode *root, TreeNode *&parent) {
        
        if (root == nullptr || root->left == nullptr) {
            parent = nullptr;
            return nullptr;
        }
        
        parent = root;
        TreeNode *curr = root->left;
        while (curr->right != nullptr) {
            
            parent = curr;
            curr = curr->right;
        }
        return curr;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        TreeNode *curr = root, *parent = nullptr;
        while (curr != nullptr) {
            
            if (key == curr->val) {
                break;
            } else if (key < curr->val) {
                parent = curr;
                curr = curr->left;
            } else if (key > curr->val) {
                parent = curr;
                curr = curr->right;
            }
        }
        
        // Not found key
        if (curr == nullptr)
            return root;

        
        if (curr->left == nullptr && curr->right == nullptr) {
            
            if (parent == nullptr) {
                // root is key
                delete root;
                return nullptr;
            } else {
                
                if (parent->left == curr) {
                    parent->left = nullptr;
                    delete curr;
                    return root;
                } else if (parent->right == curr) {
                    parent->right = nullptr;
                    delete curr;
                    return root;
                }
            }
            
        } else if (curr->right != nullptr) {
            
            TreeNode *succ = nullptr, *parent = nullptr;
            succ = successor(curr, parent);
            
            // Replace curr with successor and delete successor
            curr->val = succ->val;
            if (parent->right == succ) {
                parent->right = succ->right;
            } else if (parent->left == succ) {
                parent->left = succ->right;
            }
            delete succ;
        } else {
            
            TreeNode *pred = nullptr, *parent = nullptr;
            pred = predecessor(curr, parent);
            
            // Replace curr with successor and delete successor
            curr->val = pred->val;
            if (parent->left == pred) {
                parent->left = pred->left;
            } else if (parent->right == pred) {
                parent->right = pred->left;
            }
            delete pred;
        }
        
        return root;
    }
};