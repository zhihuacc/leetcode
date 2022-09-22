class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> ans;
        for (int n_A = A.size(), n_B = B.size(), i = 0, j = 0;
            i < n_A && j < n_B;) {
            
            if (A[i][1] < B[j][0]) {
                i++;
            } else if (B[j][1] < A[i][0]) {
                j++;
            } else {
                
                if (A[i][1] <= B[j][1]) {
                    ans.push_back({std::max(A[i][0], B[j][0]), A[i][1]});
                    i++;
                } else if (B[j][1] < A[i][1]) {
                    ans.push_back({std::max(A[i][0], B[j][0]), B[j][1]});
                    j++;
                } 
            }
        }
        
        return ans;
    }
};