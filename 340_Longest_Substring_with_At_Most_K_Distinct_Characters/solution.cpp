class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        unordered_map<char, int> counters;
        int max_len = 0;
        for (int n = s.length(), left = 0, right = 0; right < n; right++) {
            
            counters[s[right]]++;
            while (counters.size() > k) {
                
                counters[s[left]]--;
                if (counters[s[left]] == 0) {
                    counters.erase(s[left]);
                }
                
                left++;
            }
            
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};