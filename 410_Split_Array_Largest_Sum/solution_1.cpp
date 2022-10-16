class Solution {  
    
    int doable(const vector<int> &nums, int m, int target) {
        
        // This algo assumes the nums contain only non-negative numbers
        int sum = 0;
        for (auto v: nums) {
            
            if (sum + v > target) {
                // cut here
                sum = 0;
                m--;
                if (m == 0)
                    return 0;
            }
            
            sum += v;
        }
        
        return 1;
    }
public:
    
    int splitArray(vector<int>& nums, int m) {
        
        int left = 0, right = 0;
        for (auto v: nums) {
            
            left = std::max(left, v);
            right += v;
        }
        
        int mid = 0;
        while (left < right) {
            
            mid = (left + right) / 2;
            if (doable(nums, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // NOTE: We can return either left or right here.
        return left;
    }
};

// Binary search