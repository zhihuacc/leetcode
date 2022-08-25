class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        
        int top_idx = -1;
        int low_bound = INT_MIN;
        for (auto v: preorder) {
            
            if (v < low_bound)
                return false;
            
            // Use preorder itself as stack in solution_1
            while (top_idx >= 0 && v > preorder[top_idx]) {
                
                low_bound = preorder[top_idx];
                top_idx--;
            }
            preorder[++top_idx] = v;
        }
        
        return true;
    }
};