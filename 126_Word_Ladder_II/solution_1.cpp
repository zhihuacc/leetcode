class Solution {
    
    unordered_map<string, vector<string>> adj_list; // graph
    vector<string> cur_path;
    vector<vector<string>> all_paths;
    
    vector<string> find_neighbors(string &word, unordered_set<string> &word_set) {
        vector<string> neighbors;

        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];

            // replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                // skip if the character is same as original or if the word is not present in the
                // word_set
                if (c == oldChar || !word_set.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }
    
    void build_bfs_graph(string beginWord, string endWord, unordered_set<string> &word_set) {
        
        std::queue<string> que;
        
        que.push(beginWord);
        while (!que.empty()) {
            
            unordered_map<string, int> visited;
            // handle current level of BFS
            for (int n = que.size(), i = 0; i < n; ++i) {
                
                string cur_word = que.front();
                que.pop();
                vector<string> neighbors = find_neighbors(cur_word, word_set);
                for (auto w: neighbors) {
                    // pointing from low level to curr level, becas we'll do DFS from endWord to beginWord later.
                    adj_list[w].push_back(cur_word);
                    
                    int &c = visited[w];
                    c++;
                    // This if-check is necessary to avoid duplicate paths.
                    // If no this check, a same word may be enqueued more than once at this level
                    if (c == 1)
                        que.push(w);
                }
            }
           
            // Remove words at curr level from wordList, 
            //   so that they can't be found as neighbors of words at lower level.
            for (auto w: visited) {
                
                word_set.erase(w.first);
            }
        }
    }
    
    void dfs(string beginWord, string endWord) {
        
        cur_path.push_back(beginWord);
        if (beginWord == endWord) {
            all_paths.push_back(vector<string>(cur_path.rbegin(), cur_path.rend()));
            cur_path.pop_back();
            return;
        }
        
        for (auto w: adj_list[beginWord]) {
            
            dfs(w, endWord);
        }
        cur_path.pop_back();
    }
    
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        
        build_bfs_graph(beginWord, endWord, word_set);
        
        dfs(endWord, beginWord);
        
        return all_paths;
    }
};

// breadth first search, depth first search