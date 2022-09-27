class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        
        int n = nums.size();
        vector<vector<int>> edges(n+1);
        vector<int> indeg(n+1, 0);
        for (auto &seq: sequences) {
            
            for (int len = seq.size(), i = 0; i < len-1; ++i) {
                
                edges[seq[i]].push_back(seq[i+1]);
                indeg[seq[i+1]]++;
            }
        }
        
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            
            if (indeg[nums[i]] == 0)
                que.push(nums[i]);
        }
        

        vector<int> rec;
        while (que.size() != 0) {
            
            if (que.size() != 1)
                return false;
            
            int u = que.front();
            rec.push_back(u);
            que.pop();
            if (nums[rec.size()-1] != u)
                return false;
            
            for (auto v: edges[u]) {
                
                indeg[v]--;
                if (indeg[v]==0) {
                    que.push(v);
                }
            }
        }
        
        return true;
    }
};

// topological sort