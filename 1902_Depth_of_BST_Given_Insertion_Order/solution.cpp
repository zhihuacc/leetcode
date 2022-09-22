class Solution {
public:
    int maxDepthBST(vector<int>& order) {
        
        // this sentinel is to prevent prev(it) from out-of-range error.
        // It should be initialized to 0 becas it will be set to 1 in the for-loop
        map<int, int> m = { {order[0], 0}};
        int ans = 0;
        // If this for-loop skips order[0], then m[order[0]] should be 1.
        for(auto val: order) {
            auto it = m.upper_bound(val);
            if (it != m.begin()) {
                m[val] = max(it->second, prev(it)->second) + 1;
            } else {
                m[val] = it->second + 1;
            }
            ans = max(ans, m[val]);
        }
        return ans;
    }
};