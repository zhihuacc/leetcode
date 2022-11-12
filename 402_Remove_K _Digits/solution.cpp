class Solution {
    
    string stack2str(stack<char> &st) {
        
        int n = st.size();
        if (n == 0)
            return "0";
        
        stack<char> st1;
        while (!st.empty()) {
            st1.push(st.top());
            st.pop();
        }
        
        string s;
        while (!st1.empty()) {
            char c = st1.top();
            if (c == '0' && s.length()==0) {
                st1.pop();
                continue;
            }
            s.push_back(c);
            st1.pop();
        }
        
        if (s.length() == 0)
            return "0";
        
        return s;
    }
public:
    string removeKdigits(string num, int k) {
        
        int n = num.length();
        if (k >= n)
            return "0";
        
        int removal = 0;
        stack<char> st;
        for (auto &cur: num) {
            
            // Can't expect the remaining str is of length n-k, e.g., ("10200",1), the result is "200".
            // if (st.size() == n-k)
            //     break;
            
            while (!st.empty()) {
                
                char top = st.top();
                if (top > cur && removal < k) {
                    // Remove if still having quota, i.e., remvoal < k
                    st.pop();
                    removal++;
                } else {
                    break;
                }
            }
            st.push(cur);
        }
        
        for (int i = 0; i < k - removal; i++)
            st.pop();
        
        return stack2str(st);
    }
};

// Monotonic stack
// https://leetcode.com/problems/remove-k-digits/