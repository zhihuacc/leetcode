class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int zero_cnt = 0;
        int total_cnt = 0;
        int max_total = 0;
        for (int n = nums.size(), left = 0, right = 0; right < n;) {
            
            total_cnt++;
            if (nums[right] == 0)
                zero_cnt++;
            
            while (zero_cnt > k) {
                
                total_cnt--;
                if (nums[left] == 0)
                    zero_cnt--;
                
                left++;
            }
            
            max_total = std::max(max_total, total_cnt);
            
            right++;
        }
        
        return max_total;
    }
};