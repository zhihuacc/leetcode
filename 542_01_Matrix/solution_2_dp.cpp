class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int nr = mat.size(), nc = mat[0].size();
        vector<vector<int>> res(nr, vector<int>(nc, std::numeric_limits<int>::max()));
        
        
        int dist = 0;
        for (int i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                }
            }
        }
        
        pair<int,int> up_left[2] = {{-1,0},{0,-1}};
        for (int i= 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                
                if (res[i][j] != std::numeric_limits<int>::max())
                    continue;
                
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
                
                // if (res[i][j] != std::numeric_limits<int>::max())
                //     continue;
                
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
        
        return res;
    }
};

// dynamic programming