class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for (int i = 0, n = numbers.size(), j = n-1;
            i < j;) {
            
            int sum = numbers[i] + numbers[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return vector<int>{i+1,j+1};
            }
        }
        
        return vector<int>();
    }
};