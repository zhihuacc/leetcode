class Node {
public:
    Node():flag(0) {}
    // = {} is necessary to avoid runtime error: member access within misaligned address
    std::array<Node*,  26> links = {}; 
    int flag;
};

class Trie {
    
    Node root;
public:
    Trie() {}
    
    void insert(string word) {
        
        Node *curr = &root;
        int i = 0;
        for (auto &c:  word) {
            
            i = c - 'a';
            if (curr->links[i] == nullptr) {
                curr->links[i] = new Node;
            } 
            
            curr = curr->links[i];
        }
        
        curr->flag = 1;
    }
    
    bool search(string word) {
        
        Node *curr = &root;
        int i = 0;
        for (auto &c:word) {
            
            i = c - 'a';
            if (curr->links[i] == nullptr) {
                return false;
            } 
            
            curr = curr->links[i];
        }
        
        if (curr->flag != 1)
            return false;
        
        return true;
    }
    
    bool startsWith(string prefix) {
        
        Node *curr = &root;
        int i = 0;
        for (auto &c:  prefix) {
            
            i = c - 'a';
            if (curr->links[i] == nullptr) {
                return false;
            } 
            
            curr = curr->links[i];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 // https://leetcode.com/problems/implement-trie-prefix-tree/