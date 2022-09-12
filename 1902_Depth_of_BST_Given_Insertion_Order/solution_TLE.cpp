// This solution will Time Limit Exceeded for [100000,99999,...,1]
class Solution {
    
    int depth(vector<int> &order, int l , int r) {
        
        if (l > r)
            return 0;
        
        if (l == r)
            return 1;
        
        int root = order[l];
        
        std::stable_partition(order.begin()+l+1, order.begin()+r+1, [root](auto v) {return v < root;});
        int i = l+1;
        for(; i <= r; ++i) {
            if (order[i]>root)
                break;
        }
        
        int left_depth = depth(order, l+1, i-1);
        int right_depth = depth(order, i, r);
        return std::max(left_depth, right_depth) + 1;
    }
public:
    int maxDepthBST(vector<int>& order) {
        
        return depth(order, 0, order.size()-1);
    }
};