class TwoSum {
    
    vector<int> nums;
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        
        nums.push_back(number);
        for (int n = nums.size(), i = n-1; i > 0; --i) {
            
            if (nums[i] < nums[i-1]) {
                std::swap(nums[i], nums[i-1]);
            }
        }
    }
    
    bool find(int value) {
        
        for (int n = nums.size(), i = 0, j = n-1;
            i < j;) {
            
            int sum = nums[i] + nums[j];
            if (sum > value) {
                j--;
            } else if (sum < value) {
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
};