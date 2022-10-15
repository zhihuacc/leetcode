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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        std::stack<TreeNode*> st;
        TreeNode *curr = root;
        // !st.empty() is necessory:
        //    curr==nullptr and !st.empyt() implies that curr is a null right child
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {

                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            res.push_back(curr->val);

            curr=curr->right;
        }
        
        return res;
    }
};

// Iterative method, stack