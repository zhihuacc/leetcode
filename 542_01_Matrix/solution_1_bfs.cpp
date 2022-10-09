class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int nr = mat.size(), nc = mat[0].size();
        vector<vector<int>> res(nr, vector<int>(nc,-1));
        pair<int,int> dirs[4] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        int dist = 0;
        queue<pair<int,int>> que;
        for (int i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                
                if (mat[i][j] == 0) {
                    que.push({i,j});
                    res[i][j] = dist;
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
                    
                    if (res[x][y] == -1) {
                        
                        que.push({x,y});
                        res[x][y] = dist;
                    }
                }
            }
        }
        
        return res;
    }
};

// breadth first search