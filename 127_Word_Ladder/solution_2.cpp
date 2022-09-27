class Solution {
    
    int forward_step(queue<pair<string, int>> &que, unordered_map<string, int> &visited,
                     unordered_map<string, int> &other_visited,
                     const string &target_word,
                     const unordered_map<string, vector<string>> &adj_list) {
        
        for (int n = que.size(), m = 0; m < n; ++m) {
            
            auto [word, dist] = que.front();
            que.pop();
            
            for (int len = word.length(), i = 0; i < len; ++i) {
                
                string int_word = word.substr(0, i) + '*' + word.substr(i+1);
                auto adj_it = adj_list.find(int_word);
                if (adj_it == adj_list.end())
                    continue;
                
                for (auto new_word: adj_it->second) {
                    
                    auto it = other_visited.find(new_word);
                    // WARN: need check it->second, becas a 0 may be added at the if-check below
                    if (it != other_visited.end() && it->second > 0)
                        return it->second + dist;
                    
                    // this check will add new key with value 0 if the key does not exist
                    if (visited[new_word] >= 1)
                        continue;
                    
                    que.push({new_word, dist+1});
                    visited[new_word] = dist+1;
                } 
            }
        }
        
        return 0;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // WARN: this is necessary becas endWord may not be in wordList
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        unordered_map<string, vector<string>> adj_list;
        for (auto w: wordList) {
            
            for (int len = w.length(), i = 0; i < len; ++i) {
                
                adj_list[w.substr(0, i) + '*' + w.substr(i+1)].push_back(w);
            }
        }
        
        unordered_map<string, int> fwd_visited, bwd_visited;
        queue<pair<string, int>> fwd_que, bwd_que;
        
        fwd_que.push({beginWord, 1});
        bwd_que.push({endWord, 1});
        fwd_visited[beginWord] = 1;
        bwd_visited[endWord] = 1; // this assumes endWord is in wordList
        int ans = 0;
        while (!fwd_que.empty() & !bwd_que.empty()) {
            
            // WARN: if use < here, begWord should be in adj_list
            if (fwd_que.size() <= bwd_que.size()) {
                ans = forward_step(fwd_que, fwd_visited, bwd_visited, endWord, adj_list);
            } else {
                ans = forward_step(bwd_que, bwd_visited, fwd_visited, endWord, adj_list);
            }
            
            if (ans > 0)
                return ans;
        }
        
        return 0;
    }
};

// bidirectional breadth first search, bi-bfs