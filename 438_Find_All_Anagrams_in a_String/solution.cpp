class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        unordered_map<char, int> freq;
        for (auto &c: p) {
            freq[c]++;
        }
        
        int to_found = freq.size();
        int found = 0;
        vector<int> res;
        unordered_map<char, int> counters;
        for (int left = 0, right = 0, n = s.length();
             right < n;
             right++) {
            
            const char &c1 = s[right];
            
            // C++20 introduces contains()
            if (freq.find(c1) == freq.end()) {
                
                // Found invalid char, reset by jumping to right.
                left = right+1;
                counters.clear();
                found = 0;
                continue;
            }

            counters[c1]++;
            if (counters[c1] == freq[c1]) {
                // Found just enough target char
                found++;
                if (found == to_found) {
                    res.push_back(left);
                    
                    // Found a target pattern, shrink left
                    const char &c0 = s[left];
                    counters[c0]--;
                    left++;
                    if (counters[c0] == freq[c0]-1) {
                        found--;
                    }
                }
            }
            
            while (counters[c1] > freq[c1]) {
                // If found too many target char, then shrink left
                const char &c0 = s[left];
                counters[c0]--;
                left++;
                if (counters[c0] == freq[c0]-1) {
                    found--;
                }
            }
            
        }
        
        return res;
    }
};

// Sliding window, Two pointer