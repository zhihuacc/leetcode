class Solution {
    
    // Return the i where nums[j] >= target s.t. j >= i
    // If duplicate numbers exist,  i may not be the smallest
    int  binary_search(const vector<int> &nums, int left, int right, int target) {
        
        while (left <= right) {
            
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid+1;
            } else if (nums[mid] > target) {
                right = mid-1;
            } else {
                return mid;
            }
        }
        
        // NOTE: left == n when target > all numbers.
        // left is always >= 0, since left is always increased
        return left;
    }
    
    int quad_search_mat(const vector<vector<int>>& matrix, int r0, int c0, int r1, int c1, int target) {
        
        if (r0 > r1 || c0 > c1)
            return 0;
        
        if (r0 == r1 && c0 == c1) {
            if (matrix[r0][c0] == target)
                return 1;
            else
                return 0;
        }
        

        int mid_row = (r0 + r1) / 2;
        int p = binary_search(matrix[mid_row], c0, c1, target);
        
        if (p <= c1 && matrix[mid_row][p] == target)
            return 1;
        
        // search upper right sub matrix
        int b1 = quad_search_mat(matrix, r0, p, mid_row-1, c1, target);
        if (b1)
            return 1;
        
        // search lower left sub matrix
        // NOTE: plus 1 is necessary
        int b0 = quad_search_mat(matrix, mid_row+1, c0, r1, p-1, target);
        if (b0)
            return 1;
        
        return 0;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        return quad_search_mat(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1, target);
    }
};

// Binary search