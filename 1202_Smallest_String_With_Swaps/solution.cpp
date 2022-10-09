class UnionFind {
    
    vector<int> parents;
    vector<int> ranks;
    int ng;

public:
    
    UnionFind(int n): parents(n, -1), ranks(n, 0), ng(n) {}
    
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
        ng--;
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
    
    int ngroups() {
        
        return ng;
    }
    
    unordered_map<int, vector<int>> groups() {
        
        unordered_map<int, vector<int>> groups;
        for (int n = parents.size(), i = 0; i < n; ++i) {
            
            groups[find(i)].push_back(i);
        }
        
        return groups;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int len = s.length();
        UnionFind uf(len);
        for (auto &p: pairs) {
            
            uf.merge(p[0], p[1]);
        }
        
        unordered_map<int, vector<int>> groups = uf.groups();
        for (auto [pid, group]: groups) {
            
            vector<char> chars;
            for (auto i: group) {
                chars.push_back(s[i]);
            }
            
            std::sort(group.begin(), group.end());
            std::sort(chars.begin(), chars.end());
            
            for (int n=group.size(), i = 0; i < n; ++i) {
                s[group[i]]=chars[i];
            }
        }
        
        return s;
    }
};

// union-find