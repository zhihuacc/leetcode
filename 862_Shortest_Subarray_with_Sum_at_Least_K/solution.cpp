class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<long> pre_sum(n+1);
        for (int i = 0; i < n; i++) {
            pre_sum[i+1] = pre_sum[i] + nums[i];
        }
        
        int min_len = numeric_limits<int>::max();
        deque<int> mono_que;
        for (int right = 0, sum = 0; right <= n; right++) {
            
            // here assumes k >= 0
            while(!mono_que.empty() && pre_sum[right] <= pre_sum[mono_que.back()]) {
                
                mono_que.pop_back();
            }
            
            while (!mono_que.empty() && (pre_sum[right] - pre_sum[mono_que.front()] >= k)) {
                
                min_len = std::min(min_len, right - mono_que.front());
                mono_que.pop_front();
            }
            
            mono_que.push_back(right);
        }
        
        return min_len != numeric_limits<int>::max() ? min_len : -1;
    }
};

// WARN: this algorithm only works for k > 0
// To solve the case when k < 0, an O(n^2) solution is to check every subarray in nested for-loop.