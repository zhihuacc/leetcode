class Solution {

public:
    int minKnightMoves(int x, int y) {
        
        queue<pair<int,int>> que;
        unordered_map<int, unordered_map<int,int>> visited;
        
        pair<int,int> target = {std::abs(x),std::abs(y)};
        pair<int,int> dirs[8] = {{1,2},{2,1},{2,-1},{1,-2},
                                 {-1,-2},{-2,-1},{-2,1},{-1,2}};
        
        int dist = 0;
        que.push({0,0});
        visited[0][0] = 1;
        while (!que.empty()) {
            
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                
                auto curr = que.front();
                que.pop();
                
                if (curr == target) {
                    return dist;
                }
                
                for (auto &d: dirs) {
                    
                    int nx = curr.first + d.first, ny = curr.second + d.second;
                    
                    // This pruning is necessary to avoid TLE
                    if (nx < -2 || ny < -2 ||
                        nx > target.first + 2 || ny > target.second + 2)
                        continue;
                    
                    // WARN: checking and setting visited before pushing queue is necessary to
                    //   avoid TLE, since otherwise, i.e., checking and setting visited after poping,
                    //   many duplicate nodes would be pushed to the queue.
                    if (visited[nx][ny] != 0)
                        continue;
                    
                    visited[nx][ny] = 1;
                    que.push({nx, ny});
                }
                
            }
            
            dist++;
        }
        
        return -1;
    }
};

// breadth first search