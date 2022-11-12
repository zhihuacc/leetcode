class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        deque<int> que;
        int n = nums.size(), r = n-k;
        for (auto &v: nums) {
            
            // r > 0 means only remove at most r elements.
            while (que.size() > 0 && que.back() > v && r > 0) {
                que.pop_back();
                r--;
            }
            que.push_back(v);
        }
        
        // NOTE: deque has iterators, but queue and stack has no iterators.
        // vector and deque are containers, while queue and stack are adaptors.
        return vector<int>(que.begin(), que.begin() + k);
    }
};

// Monotonic stack