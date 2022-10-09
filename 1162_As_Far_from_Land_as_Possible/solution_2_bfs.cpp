class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int nr = grid.size(), nc = grid[0].size();
        pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        int dist = 2;
        queue<pair<int,int>> que;
        for (int i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                
                if (grid[i][j] == 1) {
                    que.push({i,j});
                    grid[i][j] = dist;
                }
            }
        }
        
        while (!que.empty()) {
            
            int n = que.size();
            
            dist++;
            for (int i = 0; i < n; ++i) {
                
                auto [x0, y0] = que.front();
                que.pop();
                
                for (auto &d: dirs) {
                    
                    int x = x0 + d.first, y = y0 + d.second;
                    if (x < 0 || x >= nr || y < 0 || y >= nc)
                        continue;
                    
                    if (grid[x][y] == 0) {
                        
                        que.push({x,y});
                        grid[x][y] = dist;
                    }
                }
            }
        }
        
        int max_min = -1;
        for (int i= nr-1; i >= 0; --i) {
            for (int j = nc-1; j >= 0; --j) {
                    
                max_min = std::max(max_min, grid[i][j]);
            }
        }
        
        if (max_min == 2 || max_min == 0)
            return -1;
        
        return max_min-2;
    }
};


// breadth first search