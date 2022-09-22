class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int min_len = std::numeric_limits<int>::max();
        for (int n = nums.size(), left = 0, right = 0, sum = 0; right < n;right++) {
            
            // extending window will increase sum
            sum += nums[right];
            while (sum >= target) {
                
                min_len = std::min(min_len, right - left + 1);
                // shrinking window will decrease sum
                sum -= nums[left];
                left++;
            }
        }
        
        return min_len != std::numeric_limits<int>::max() ? min_len : 0;
    }
};

// WARN: this algorithm works only when nums contains only non-negative numbers.
//   Under this assumption, rightward extending window will increase sum while
//   shrking window will decrease sum. This is not the case if the nums contain negative numbers.