class Solution {  
public:
    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size();
        vector<int> pre_sum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            pre_sum[i+1] = pre_sum[i] + nums[i];
        }
        
        
        vector<vector<int>> memo(n, vector<int>(m+1, -1));
        for (int step = 1; step <= m; ++step) {
            for (int start = 0; start <= n - step; ++start) {
                
                if (step == 1) {
                    memo[start][step] = pre_sum[n] - pre_sum[start];
                    continue;
                }
                
                int this_sum = 0, max_sum = -1, min_max_sum = INT_MAX;
                // WARN: k <= n-step+1 cant be changed to k<n. 
                //   Otherwise, invalid memo value would be used.
                for (int k = start + 1; k <= n - step + 1; ++k) {
                    this_sum = pre_sum[k] - pre_sum[start];
                    
                    max_sum = max(this_sum, memo[k][step - 1]);
                    // if max_sum at k is greater than the best result, no need to continue
                    //   because with greater k this_sum would be greater and hence max_sum greater
                    if (max_sum > min_max_sum)
                        break;
                    
                    min_max_sum = min(min_max_sum, max_sum);
                }
                
                memo[start][step] = min_max_sum;
            }
        }
        
        return memo[0][m];
    }
};

// Bottom-up, Dynamic programming