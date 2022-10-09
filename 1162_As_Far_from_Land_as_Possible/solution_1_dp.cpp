class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        
        int nr = grid.size(), nc = grid[0].size();
        vector<vector<int>> res(nr, vector<int>(nc, std::numeric_limits<int>::max()));
        
        int dist = 0;
        for (int i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                
                if (grid[i][j] == 1) {
                    res[i][j] = 0;
                }
            }
        }
        
        pair<int,int> up_left[2] = {{-1,0},{0,-1}};
        for (int i= 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                
                for (auto &d: up_left) {
                    int x = i + d.first, y = j + d.second;
                    if (x < 0 || x >= nr || y < 0 || y >= nc)
                        continue;

                    if (res[x][y] != std::numeric_limits<int>::max()) {
                        
                        res[i][j] = std::min(res[i][j], res[x][y]+1);
                    }
                }
            }
        }
        
        pair<int,int> down_right[2] = {{1,0},{0,1}};
        for (int i= nr-1; i >= 0; --i) {
            for (int j = nc-1; j >= 0; --j) {
                
                for (auto &d: down_right) {
                    int x = i + d.first, y = j + d.second;
                    if (x < 0 || x >= nr || y < 0 || y >= nc)
                        continue;

                    if (res[x][y] != std::numeric_limits<int>::max()) {
                        
                        res[i][j] = std::min(res[i][j], res[x][y]+1);
                    }
                }
            }
        }
        
        int max_min = -1;
        for (int i= nr-1; i >= 0; --i) {
            for (int j = nc-1; j >= 0; --j) {
                    
                max_min = std::max(max_min, res[i][j]);
            }
        }
        
        // check all 0 or all 1 cases
        if (max_min == std::numeric_limits<int>::max()
           || max_min == 0)
            return -1;
        else
            return max_min;
    }
};

// bottom-up dynamic programming