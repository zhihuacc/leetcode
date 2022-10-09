class Solution {
    
    int dfs(int i, int j, vector<vector<int>> &grid, int clr) {
        
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return 0;
        
        if (grid[i][j] == 1) {
            
            grid[i][j] = clr;
            return 1 + dfs(i, j+1, grid, clr) + dfs(i, j-1, grid, clr) 
                   + dfs(i+1, j, grid, clr) + dfs(i-1, j, grid, clr);
        } else {
            // if it's water or other islands
            return 0;
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        unordered_map<int, int> island_sizes;
        for (int nr = grid.size(), nc = grid[0].size(), i = 0, clr = 2; i < nr; ++i) {
            for (int j = 0; j < nc; j++) {
                
                if (grid[i][j] == 1) {
                    
                    island_sizes[clr] = dfs(i, j, grid, clr);
                    clr++;
                }
            }
        }
        
        int max_size = 0;
        pair<int, int> dirs[] = {{0,1},{0,-1},{1,0},{-1,0}};
        for (int nr = grid.size(), nc = grid[0].size(), i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; j++) {
                
                if (grid[i][j] == 0) {
                    // Search for colored islands beside (i,j)
                    unordered_set<int> found_clr;
                    for (auto [di, dj]: dirs) {
                        
                        int ni = i + di, nj = j + dj;
                        if (ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size())
                            continue;
                        
                        if (grid[ni][nj] != 0) {
                            found_clr.insert(grid[ni][nj]);
                        }
                    }
                    
                    // int sum = 0;
                    // for (auto c: found_clr) {
                    //     sum += island_sizes[c];
                    // }
                    int sum = std::accumulate(std::begin(found_clr), std::end(found_clr), 0,
                                             [&island_sizes](int a, int b) {return a + island_sizes[b];});
                    
                    max_size = std::max(max_size, sum+1);
                }
            }
        }
        
        if (max_size == 0)
            return grid.size() * grid[0].size();
        else
            return max_size;
    }
};