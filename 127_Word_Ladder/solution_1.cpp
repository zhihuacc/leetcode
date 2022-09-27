class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, vector<string>> adj_list;
        for (auto w: wordList) {
            
            for (int len = w.length(), i = 0; i < len; ++i) {
                
                adj_list[w.substr(0, i) + '*' + w.substr(i+1)].push_back(w);
            }
        }
        
        unordered_map<string, int> visited;
        queue<pair<string, int>> que;
        que.push({beginWord, 1});
        visited[beginWord] = 1;
        while (!que.empty()) {
            
            auto [word, dist] = que.front();
            que.pop();
            for (int len = word.length(), i = 0; i < len; ++i) {
                
                string int_word = word.substr(0, i) + '*' + word.substr(i+1);
                auto it = adj_list.find(int_word);
                if (it == adj_list.end())
                    continue;
                
                for (auto new_word: it->second) {
                    
                    if (new_word == endWord)
                        return dist + 1;
                    
                    if (visited[new_word] == 1)
                        continue;
                    
                    que.push({new_word, dist+1});
                    visited[new_word] = 1;
                } 
            }
        }
        
        return 0;
    }
};

// breadth first search