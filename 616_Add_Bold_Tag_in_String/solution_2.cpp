class Solution {
    
    vector<int> kmp_prep_pattern(const string &pattern) {
        
        int m = pattern.size();
        vector<int> next(m+1, 0);
        next[0] = -1;
        for (int i = 1, j = 0; i < m;) {
            
            if (pattern[i] == pattern[j]) {
                // pattern[0...j] is the same as pattern[i-j...i]
                // i.e., pattern[0...j] is a suffix of pattern[0...i]
                // so if mismatch at i+1, can pattern[0...j]
                next[++i] = ++j;
            } else {
                j = next[j];
                if (j == -1) {
                    i++;
                    j = 0;
                }
            }
        }
        
        return next;
    }
    
    vector<int> kmp_search(const string &text, const string &pattern) {
        
        vector<int> found;
        vector<int> next = kmp_prep_pattern(pattern);
        for (int i = 0, j = 0, n = text.size(), m = pattern.size(); i < n;) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
                if (j == m) {
                    // Found one
                    found.push_back(i-m);
                    j = next[m];
                }
            } else {
                j = next[j];
                if (j == -1) {
                    i++;
                    j = 0;   
                }
            }
        }
        
        return found;
    }
public:
    string addBoldTag(string s, vector<string>& words) {
        
        vector<bool> tags(s.length(), false);
        for (auto &p: words) {
            vector<int> found = kmp_search(s, p);
            int m = p.length();
            for (auto start: found) {
                std::fill(tags.begin()+start, tags.begin()+start+m, true);
            }
            
        }
        
        string res;
        int f = 0;
        for (int i = 0, n = s.length(); i < n; i++) {
            
            if (f == 0 && tags[i]) {
                // s[i] is the start of a tag
                // res.push_back('<b>');
                res += "<b>";
                res.push_back(s[i]);
                
                f = 1;
            } else if (f == 1 && tags[i]) {
                // s[i] is part of a tag
                res.push_back(s[i]);
            } else if (f == 1 && !tags[i]) {
                // s[i-1] is the last letter of a tag
                // but s[i] itself is not part of a tag
                res += "</b>";
                res.push_back(s[i]);
                
                f = 0;
            } else {
                res.push_back(s[i]);
            }
        }
        
        if (f == 1)
            res += "</b>";
        
        return res;
    }
};

// KMP algo