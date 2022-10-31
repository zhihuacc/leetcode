class Node {
public:
    Node():flag(0) {}
    // = {} is necessary to avoid runtime error: member access within misaligned address
    std::array<Node*,  62> links = {}; 
    int flag;
};

class Trie {
    
    Node root;
    
    int char2idx(char c) {
        if (c >= '0' && c <= '9')
            return c -  '0';
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 10;
        if (c >= 'a' && c <= 'z')
            return c - 'a' + 26;
        return -1;
    }
public:
    Trie() {}
    
    void insert(string word) {
        
        Node *curr = &root;
        for (auto &c:  word) {
            
            int r = char2idx(c);
            if (curr->links[r] == nullptr) {
                curr->links[r] = new Node;
            } 
            
            curr = curr->links[r];
        }
        
        curr->flag = 1;
    }
    
    
    int lcs(string word, int start) {
        
        
        Node *curr = &root;
        int end = -1;
        for (int j = start, n = word.length(); j < n; ++j) {
            
           
            int r = char2idx(word[j]);
            if (curr->links[r] == nullptr) {
                break;
            } 
            
            curr = curr->links[r];
            if (curr->flag == 1) {
                // continuing for the longest common seq
                end = j;
            }
        }
        
        return end;
    }
};

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        
        Trie dict;
        for (auto &w: words) {
            dict.insert(w);
        }
        
        vector<bool> tags(s.length(), false);
        for (int start = 0, n = s.length(); start < n; start++) {
            int end = dict.lcs(s, start);
            for (int i = start; i <= end; ++i) {
                tags[i] = true;
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

// Trie