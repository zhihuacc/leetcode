class Solution {
    
    int at_most(vector<int>& nums, int k) {
        
        unordered_map<int,int> counters;
        int ans = 0;
        for (int n = nums.size(), left = 0, right = 0; right < n;right++) {
            
            counters[nums[right]]++;
            while(counters.size() > k) {
                
                counters[nums[left]]--;
                if (counters[nums[left]] == 0) {
                    counters.erase(nums[left]);
                }
                
                left++;
            }
            
            ans += right - left + 1;
        }
        
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return at_most(nums, k) - at_most(nums, k - 1);
    }
};

// Sliding window, two pointer