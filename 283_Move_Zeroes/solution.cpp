class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int slow = 0,  n = nums.size();
        for (int fast = 0; fast < n; fast++) {
            
            if (nums[fast] != 0) {
                
                nums[slow++] = nums[fast];
            }
        }
        
        for (; slow < n; slow++) {
            
            nums[slow]=0;
        }
    }
};