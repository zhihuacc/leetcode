class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> map;
        for (int n = nums.size(), i = 0; i < n; i++) {
            
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                // It ensures that nums[i] is used only once,
                //   becas up to now, nums[i] has not been added in map.
                return vector<int>{i, map[complement]};
            }
            map[nums[i]] = i;
        }
        
        return vector<int>();
    }
};