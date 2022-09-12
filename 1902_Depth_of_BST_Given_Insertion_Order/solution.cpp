class Solution {
public:
    int maxDepthBST(vector<int>& order) {

        // this sentinel is to prevent prev(it) from out-of-range error.
        // It should be initialized to 0 becas it will be set to 1 in the for-loop
        map<int, int> m = { {order[0], 0}};
        int ans = 0;
        for(auto val: order) {
            auto it = m.upper_bound(val);
            m[val] = max(it->second, prev(it)->second) + 1;
            ans = max(ans, m[val]);
        }
        return ans;
    }
};