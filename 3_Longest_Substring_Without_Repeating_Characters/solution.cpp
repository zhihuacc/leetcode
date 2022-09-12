class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> memo;
        int ans = 0;
        for (int i = 0, j = 0, n = s.length(); j < n; ++j) {
            
            if (memo[s[j]] > 0) {
                // c is a duplicate
                // WARN: can't use i = memo[s[j]] becas i can't go back
                //   as in case "abba"
                i = std::max(memo[s[j]], i);
            }
            memo[s[j]] = j+1;
            ans = std::max(ans, j-i+1);
        }
        return ans;
    }
};