class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        
        stack<int> st;
        while (n != 0) {
            st.push(n % 10);
            n /= 10;
        }
        
        int m = st.size();
        vector<int> nums(m, 0);
        for (int i = 0; i < m; i++) {
            nums[i] = st.top();
            st.pop();
        }
        
        int leftmost = m-1;
        for (int i = m-1; i > 0; i--) {
            if (nums[i-1] > nums[i]) {
                nums[i-1]--;
                leftmost = i-1;
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            if (i <= leftmost) {
                res += (nums[i] * pow(10, m-1 - i));
            } else {
                res += (9* pow(10, m-1 - i));
            }
        }
        
        return res;
    }
};