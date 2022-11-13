class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0], fast = nums[0];
        do  {
            slow = nums[slow];
            fast = nums[nums[fast]]; // There must be a cycle, so no need check index range.
        } while (slow != fast);
        
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

// fast slow pointer, floyd algorithm
// NOTE: this algo can only find one duplicated number if mulitple duplicated numbers exist 
// https://leetcode.com/problems/find-the-duplicate-number/