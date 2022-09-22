class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int, int> baskets;
        int max_cnt = 0;
        int cur_cnt = 0;
        for (int n = fruits.size(), left = 0, right = 0; right < n;) {
            
            baskets[fruits[right]]++;
            cur_cnt++;
            while (baskets.size() > 2) {
                
                int &c = baskets[fruits[left]];
                c--;
                cur_cnt--;
                if (c == 0) {
                    baskets.erase(fruits[left]);
                }
                
                left++;
            }
            
            max_cnt = std::max(max_cnt, cur_cnt);
            
            right++;
        }
        
        return max_cnt;
        
    }
};