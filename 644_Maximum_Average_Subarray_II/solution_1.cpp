class Solution {
    
    int bigger_avg_exists(const vector<int>  &nums,  int k, double target)  {
        
        double left_sum = 0, right_sum = 0, min_left_sum = 0;
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            right_sum += nums[i] - target;
        }
        
        // Change to <= if wanting min avg
        if (right_sum >= 0)
            return  1;
        
        for (int i = k; i < n; ++i) {
            right_sum += nums[i] - target;
            left_sum += nums[i-k] - target;
            
            // Change to max if wanting min avg
            min_left_sum = std::min(min_left_sum, left_sum);
            if (right_sum - min_left_sum >= 0) // Change to <= if wanting min avg
                return 1;
        }
        
        return 0;
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double left = std::numeric_limits<double>::max(), right = std::numeric_limits<double>::min();
        for (auto v: nums) {
            
            left = std::min(left,  double(v));
            right = std::max(right, double(v));
        }
        
        while (std::abs(right - left) > 1e-5) {
            
            double mid = (left + right) / 2;
            if (bigger_avg_exists(nums, k, mid)) {
                // Change to right=mid if wanting min avg
                left = mid;
            } else {
                // Change to left=mid if wanting min avg
                right = mid;
            }
        }
        
        return left;
    }
};

// Binary search
// NOTE: same idea can solve finding min average with at least k 
// NOTE: There is a O(n) solution using convex hull window, 
//   https://leetcode.com/problems/maximum-average-subarray-ii/discuss/105476/Python-Advanced-O(n)-solution-(Convex-Hull-Window)