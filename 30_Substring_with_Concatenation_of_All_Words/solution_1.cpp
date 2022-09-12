class Solution {
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = s.length(), w = words.size(), m = words[0].length();
        
        map<string, int> counters, found_counters;
        int found_words = 0;
        for (auto w: words) {
            counters[w]++;
        }
        
        vector<int> ans;
        for (int offset = 0; offset < m; ++offset) {
            for (int left = offset, right = left; right < n - m + 1; right += m) {
                
                string new_word = s.substr(right, m);
                if (counters.find(new_word) != counters.end()) {
                    // Found a target word
                    found_counters[new_word]++;
                    found_words++;
                    if (found_counters[new_word] > counters[new_word]) {
                        
                        // if the new_word is found more times than should be,
                        //   slide the window to right word by word, to 
                        //   remove left-most words from found substring
                        //   until the freq of the new_word is below counters[new_word].
                        while (found_counters[new_word] > counters[new_word]) {
                            
                            string left_most = s.substr(left, m);
                            found_counters[left_most]--;
                            found_words--;
                            left += m;
                        }

                    } else if (found_words == w) {
                        
                        // Found a valid substring
                        ans.push_back(left);
                        // Slide window to right by only one word i.e., m to continue searching
                        //   next valid substring.
                        // WARN: Not shrink window size to one word, i.e, 
                        //   NOT clear found_counters and found_words to save computation.
                        // WARN: Not slide by w*m, otherwise may miss valid substrings.
                        string left_most = s.substr(left, m);
                        found_counters[left_most]--;
                        found_words--;
                        left += m;
                    }
                } else {
                    // Found a non-target word,
                    //   slide to the word after the non-target one.
                    found_words = 0;
                    found_counters.clear();
                    left = right + m;
                }
            }
            // Reset
            found_words = 0;
            found_counters.clear();
        }
        
        return ans;
    }
};