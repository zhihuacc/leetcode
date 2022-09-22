class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        // Use array<int,3> to store <height, x, y>
        auto comp = [](const std::array<int,3> &a, const std::array<int,3> &b) { return a[0] >= b[0];};
        // Must provide comp as arg for the constructor.
        std:priority_queue<std::array<int,3>, vector<std::array<int,3>>, decltype(comp)> min_heap(comp);
        
        for (int i = 0; i < m; i++) {
            
            min_heap.push({heightMap[i][0], i, 0});
            visited[i][0] = 1;
            min_heap.push({heightMap[i][n-1], i, n-1});
            visited[i][n-1] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            
            min_heap.push({heightMap[0][i], 0, i});
            visited[0][i] = 1;
            min_heap.push({heightMap[m-1][i], m-1, i});
            visited[m-1][i] = 1;
        }
        
        int vol = 0;
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        while (!min_heap.empty()) {
            
            // Must use auto instead of int.
            // This height is the min height of max heights along paths that HAVE been extended to [x,y]
            //    and half-paths that have NOT been extended to [x,y]
            // => this height is the min height of max heights along all possible paths leading to [x,y] 
            // IDEA: Find min of max of a number of sets <== Find min of max/partial max of a number of sets
            //       <== partial max of a set >= max of a set
            auto [height, x, y] = min_heap.top();
            min_heap.pop();
            
            for (auto d: dirs) {
                
                int x0 = x + d[0], y0 = y + d[1];
                if (x0 >= 0 && x0 < m && y0 >= 0 && y0 < n && !visited[x0][y0]) {
                    
                    vol += std::max(0, height - heightMap[x0][y0]);
                    min_heap.push({std::max(height, heightMap[x0][y0]), x0, y0});
                    visited[x0][y0] = 1;
                }
            }
        }
        
        return vol;
    }
};