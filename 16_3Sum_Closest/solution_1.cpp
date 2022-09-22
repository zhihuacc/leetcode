class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX, three_sum;
        for (int i = 0; i < n-2; ++i) {
            
            int remaining = target - nums[i];
            for (int low = i+1, high = n-1; low < high;) {
                
                int two_sum = nums[low] + nums[high];
                if (std::abs(two_sum - remaining) < diff) {
                    
                    diff = std::abs(two_sum - remaining);
                    three_sum = two_sum + nums[i];
                }
                
                if (two_sum < remaining) {
                    low++;
                } else if (two_sum > remaining) {
                    high--;
                } else {
                    return target;
                }
            }
        }
        
        return three_sum;
    }
};