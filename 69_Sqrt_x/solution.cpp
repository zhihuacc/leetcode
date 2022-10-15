class Solution {
public:
    int mySqrt(int x) {
        
        int left = 0, right = x, mid;
        long sq;
        // WARN: Using left < right causes wrong answers.
        while (left <= right) {
            
            mid = (left + right) / 2;
            sq = (long)mid*mid;
            if (sq == x) {
                return mid;
            } else if (sq < x) {
                left = mid + 1; // WARN: this +1 may take 'left' beyond the right answer. So, can't return left at the end.
            } else {
                right = mid -1;
            }
        }
        
        // WARN: returning left causes wrong answers.
        return right;
    }
};

// Binary search