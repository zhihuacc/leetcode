class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        for (int n = nums.size(), i = n-1; i > 0; i--){
            
            if (nums[i-1] < nums[i]) {
                // largest permutation leading with nums[i-1]
                for (int j = n-1; j > i-1; j--) {
                    
                    if (nums[j] > nums[i-1]) {
                        // Found next leading digit
                        swap(nums[j], nums[i-1]);
                        sort(nums.begin() + i, nums.end());
                        return;
                    }
                }
            }
        }
        
        return reverse(nums.begin(), nums.end());
    }
};

// https://leetcode.com/problems/next-permutation/