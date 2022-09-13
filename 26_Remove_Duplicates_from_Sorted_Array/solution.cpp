class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int slow = 0;
        for (int fast = 0, n = nums.size();
            fast < n; fast++) {
            
            if (nums[slow] != nums[fast]) {
                nums[++slow] = nums[fast];
            }
        }
        
        return slow+1;
    }
};