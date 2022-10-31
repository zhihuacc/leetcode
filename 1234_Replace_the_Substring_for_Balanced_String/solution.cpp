class Solution {
    
    // NOTE: a valid substr are those makeing chars OUTSIDE the substr less than 4/n.
    //   chars in the substr can be UNchanged, so # of chars IN the substr can be any.
    int valid(const unordered_map<char, int> &counters, int t) {
       
        for (auto &p: counters) {
            
            if (p.second > t)
                return 0;
        }
        
        return 1;
    }
public:
    int balancedString(string s) {
        
        unordered_map<char,  int> counters = {{'Q',0}, {'W',0}, {'E',0}, {'R',0}};
        for (auto c: s) {
            counters[c]++;
        }
        
        int n = s.length(), t = n/4, found = 0;
        if (valid(counters, t))
            return 0;
        
        int min_len = n;
        for (int left = 0,  right = 0;  right < n; right++) {
            
            const char &c1 = s[right];
            
            // counts of each char OUTSIDE the current window.
            // so minus instead of plus
            counters[c1]--;
            while (valid(counters, t) && left <= right) {
                
                min_len = std::min(min_len, right-left+1);
                counters[s[left++]]++;
            }

        }
       
        return min_len;
    }
};

// Sliding Window, two pointer