class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        auto count_smaller_equal = [&nums] (int v) {
            int count = 0;
            for (auto &w: nums) {
                if (w <= v)
                    count++;
            }
            return count;
        };
        
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (count_smaller_equal(mid) > mid) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        
        return left;
    }
};

// Binary search
// https://leetcode.com/problems/find-the-duplicate-number/