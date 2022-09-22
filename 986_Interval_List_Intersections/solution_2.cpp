class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> ans;
        for (int n_A = A.size(), n_B = B.size(), i = 0, j = 0;
            i < n_A && j < n_B;) {
            
            int low = std::max(A[i][0], B[j][0]);
            int high = std::min(A[i][1], B[j][1]);
            if (low <= high) {
                ans.push_back({low,high});
            }

            if (A[i][1] <= B[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        
        return ans;
    }
};