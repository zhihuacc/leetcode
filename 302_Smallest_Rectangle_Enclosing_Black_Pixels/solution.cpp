class Solution {
    
    int bfs_col(vector<vector<char>>& image, int left, int right, int top, int bot, bool wtb) {
        
        while (left < right) {
            
            int mid = (left + right) / 2;
            
            // Check this col has '1' or not
            int k = top;
            while (k < bot && image[k][mid] == '0')
                k++;
            
            if (k == bot) {
                // NO '1',  this is a white col
                if (wtb) {
                    // we want black col, so plus 1.
                    left = mid+1;
                } else {
                    // we want white col, so no plus 1.
                    right = mid; 
                }
            } else {
                // this is a black col
                if (wtb) {
                    // we want black col, so no plus 1.
                    right = mid;
                } else {
                    // we want white col, so plus 1.
                    left = mid+1;
                }
            }   
        }
        
        return left;
    }
    
    int bfs_row(vector<vector<char>>& image, int top, int bot, int left, int right, bool wtb) {
        
        while (top < bot) {
            
            int mid = (top + bot) / 2;
            
            // Check this col has '1' or not
            int k = left;
            while (k < right && image[mid][k] == '0')
                k++;
            
            if (k == right) {
                // NO '1',  this is a white row
                if (wtb)
                    top = mid+1;
                else
                    bot = mid;
            } else {
                // this is a black row
                if (wtb)
                    bot = mid;
                else
                    top = mid+1;
            }   
        }
        
        return top;
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        // x is row, y is col
        
        int nr = image.size(), nc = image[0].size();
        int c0 = bfs_col(image, 0, y, 0, nr, true);
        int r0 = bfs_row(image, 0, x, 0, nc, true);
        int c1 = bfs_col(image, y, nc, 0, nr, false);
        int r1 = bfs_row(image, x, nr, 0, nc, false);
        
        return (c1-c0) * (r1-r0);
    }
};