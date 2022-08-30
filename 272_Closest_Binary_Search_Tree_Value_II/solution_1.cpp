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
    
    void inorder_traverse(TreeNode *root, vector<int> &sorted) {
        
        if (root == nullptr)
            return;
        
        inorder_traverse(root->left, sorted);
        sorted.push_back(root->val);
        inorder_traverse(root->right, sorted);
    }
    
    // return the idx of the pivot after the partition
    int partition(vector<int> &nums,  const map<int, double> &dists, int left, int right, int pivot_idx) {
       
        std::swap(nums[pivot_idx], nums[right]); // move pivot to the end
        // Use at() instead of [] to avoid compiling error.
        //   the [] operator may insert 0 if the key does not exists, i.e., [] is not const.
        double pivot_dist = dists.at(nums[right]);
        
        int left_end = left;
        for (int i = left; i < right; i++)
        {
            if (dists.at(nums[i]) < pivot_dist) {
                
                std::swap(nums[left_end], nums[i]);
                left_end++;
            }
        }
        
        std::swap(nums[left_end], nums[right]);
        return left_end;
    }
    
    void quick_select(vector<int> &nums,  const map<int, double> &dists, int left, int right, int k) {
        
        if (left >= right)
            return;
        
        int pivot_idx = left + std::rand() % (right - left +1);
        pivot_idx = partition(nums, dists, left, right, pivot_idx);
        if (pivot_idx == k)
            return;
        else if (pivot_idx < k) {
            // not enough, go to right half
            quick_select(nums, dists, pivot_idx+1, right, k);
        } else {
            quick_select(nums, dists, left, pivot_idx-1, k);
        }
    }
    
public:
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        
        vector<int> sorted_values;
        inorder_traverse(root, sorted_values);
        
        map<int, double> dists;
        for (auto v: sorted_values) {
            dists[v] = std::abs(target - v);
        }
        
        quick_select(sorted_values, dists, 0, sorted_values.size()-1, k);
        return vector<int>(sorted_values.begin(), sorted_values.begin()+k);
    }
};