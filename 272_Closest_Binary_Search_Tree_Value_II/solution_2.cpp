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
    
    double target;
    
    void inorder_traverse(TreeNode *root, vector<int> &sorted) {
        
        if (root == nullptr)
            return;
        
        inorder_traverse(root->left, sorted);
        sorted.push_back(root->val);
        inorder_traverse(root->right, sorted);
    }
    // compute dist everytime is faster than map<int,double>
    double dist(double x, double y) const {
        return std::abs(x-y);
    }
    
    // return the idx of the pivot after the partition
    int partition(vector<int> &nums, double target, int left, int right, int pivot_idx) {
       
        std::swap(nums[pivot_idx], nums[right]); // move pivot to the end
        
        double pivot_dist = dist(target, nums[right]);
        
        int left_end = left;
        for (int i = left; i < right; i++)
        {
            if (dist(target, nums[i]) < pivot_dist) {
                
                std::swap(nums[left_end], nums[i]);
                left_end++;
            }
        }
        
        std::swap(nums[left_end], nums[right]);
        return left_end;
    }
    
    void quick_select(vector<int> &nums, double target, int left, int right, int k) {
        
        if (left >= right)
            return;
        
        int pivot_idx = left + std::rand() % (right - left +1);
        pivot_idx = partition(nums, target, left, right, pivot_idx);
        if (pivot_idx == k)
            return;
        else if (pivot_idx < k) {
            // not enough, go to right half
            quick_select(nums, target, pivot_idx+1, right, k);
        } else {
            quick_select(nums, target, left, pivot_idx-1, k);
        }
    }
    
public:
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        
        vector<int> sorted_values;
        inorder_traverse(root, sorted_values);
       
        
        quick_select(sorted_values, target, 0, sorted_values.size()-1, k);
        return vector<int>(sorted_values.begin(), sorted_values.begin()+k);
    }
};