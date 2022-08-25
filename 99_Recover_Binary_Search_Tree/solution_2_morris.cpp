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
   
    TreeNode *x;
    TreeNode *y;

public:
    
    void recoverTree(TreeNode* root) {
        
        if (root == nullptr)
            return;
        TreeNode *curr = nullptr, *pred = nullptr, *x = nullptr, *y = nullptr;
        
        curr = root;
        while (curr != nullptr) {
            
            if (curr->left != nullptr) {
                // If there is a left tree, then search for the predecessor of curr anyway.
                TreeNode *temp_pred = curr->left;
                while (temp_pred->right != nullptr && temp_pred->right != curr)
                    temp_pred = temp_pred->right;
                
                
                if (temp_pred->right == nullptr) {
                    // If there is no link btw the found pred and curr, create a temp one and
                    //    then go to curr->left
                
                    temp_pred->right = curr;
                    curr = curr->left;
                }
                else {
                    // If there is a link btw the pred and curr, this means coming back to curr 
                    //    from the pred via the link, i.e., finishing visiting left subtree.
                    
                    // Check if (pred, curr) is a swapped pair
                    if (pred != nullptr && curr->val < pred->val) {
                        // Found a swapped pair
                        if (x == nullptr) {
                            // It's the first pair
                            x = pred;
                            y = curr;
                        } else {
                            // It's the second pair
                            y = curr;
                        }
                    } else {
                        pred = curr;
                    }
                    
                    // Remove the link to restore the tree structure and go to curr-right.
                    temp_pred->right = nullptr;
                    curr = curr->right;
                }
                
            } else {
                // If there is no left tree, just go to curr-right
                
                // Check if (pred, curr) is a swapped pair
                if (pred != nullptr && curr->val < pred->val) {
                    // Found a swapped pair
                    if (x == nullptr) {
                        // It's the first pair
                        x = pred;
                        y = curr;
                    } else {
                        // It's the second pair
                        y = curr;
                    }
                } else {
                    pred = curr;
                }
                
                curr = curr->right;
            }
        }
        
        std::swap(x->val, y->val);
    }
};