class UnionFind {
    
    vector<int> parents;
    vector<int> ranks;
    int groups;

public:
    
    UnionFind(int n): parents(n, -1), ranks(n, 0), groups(n) {}
    
    int find(int x) {
        
        if (parents[x] == -1)
            return x;
        
        // path compression: make parents of the nodes from x (inclusive) 
        //   to root (exclusive) as root
        return parents[x] = find(parents[x]);
    }
    
    int merge(int x, int y) {
        
        int px = find(x);
        int py = find(y);
        
        if (px == py)
            return px;
        
        // union by rank: attch the smaller tree to the root of the larger tree
        //   to reduce the height of the union tree.
        groups--;
        if (ranks[px] > ranks[py]) {
            
            parents[py] = px;
            return px;
        } else if (ranks[px] < ranks[py]) {
            
            parents[px] = py;
            return py;
        } else {
            
            parents[px] = py;
            ranks[py]++;
            return py;
        }
    }
    
    int count() {
        
        return groups;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                
                if (i == j)
                    continue;
                
                if (isConnected[i][j] == 1) {
                    uf.merge(i, j);
                }
            }
        }
        
        return uf.count();
    }
};


// Union-find, path compression, union by rank