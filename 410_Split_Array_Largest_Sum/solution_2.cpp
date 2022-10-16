class Solution { 
    
    int dfs(const vector<int> &pre_sums, int start, int k,
            vector<vector<int>> &memo) {
        
        int n = pre_sums.size()-1;
        if (start > n-k) {
            return 0;
        }
        
        if (memo[start][k] != -1)
            return memo[start][k];
        
        if (k == 1)
            return memo[start][k] = pre_sums[n] - pre_sums[start];
        
        int min_max_sum = INT_MAX;
        for (int i = start; i <= n-k; ++i) {
            
            int first_sum = pre_sums[i+1] - pre_sums[start];
            int max_sum = std::max(first_sum, dfs(pre_sums, i+1, k-1, memo));
            min_max_sum = std::min(min_max_sum, max_sum);
        }
        
        memo[start][k] = min_max_sum;
        return min_max_sum;
    }
public:
    
    int splitArray(vector<int>& nums, int m) {
        
        vector<int> pre_sums(nums.size()+1, 0);
        for (int n = nums.size(), i = 1; i <= n; ++i) {
            pre_sums[i] = pre_sums[i-1] + nums[i-1];
        }
        
        vector<vector<int>> memo(nums.size(), vector<int>(m+1, -1));
        return dfs(pre_sums, 0, m, memo);
    }
};

// Top-down, Dynamic programming
