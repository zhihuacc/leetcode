class Solution {
    
    int doable(const vector<int> &quantities, int n, int x) {
        
        int k = 0;
        for (int m = quantities.size(), i = 0; i < m;i++) {
            
            k += ((quantities[i] + x - 1) / x);
        }
        
        return k <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int left = 0, right = 0;
        for (int m = quantities.size(), i = 0; i < m; ++i) {
            
            left += (quantities[i] / n);
            right = std::max(right, quantities[i]);
        }
        
        left = std::max(left, 1);
        
        while (left < right) {
            
            int mid = (left + right) / 2;
            if (doable2(quantities, n, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        
        return left;
    }
};