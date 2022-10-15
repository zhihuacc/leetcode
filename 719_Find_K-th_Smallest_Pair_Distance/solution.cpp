class Solution {
    
    int count_smaller(const vector<int> &nums, int val) {
        
        int count = 0;
        for (int n = nums.size(), left = 0, right = left+1; right < n; ++right) {
            
            while (nums[right] - nums[left] > val) {
                left++;
            }
            
            count += (right - left);
        }
        
        return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        std::sort(nums.begin(), nums.end());
        
        int left = 0, right = nums[nums.size()-1] - nums[0], mid, count;
        // WARN: this condition can't be left <= right.
        //   Otherwise, the loop would be endless.
        while (left < right) {
            
            mid = (left+right)/2;
            
            count = count_smaller(nums, mid);
            // WARN: can't return mid directly when count == k.
            //   becas mid may be greater than the target k-th dist,
            //   actually, mid may be not real dist in input, 
            //   it may be some number btw k-th and k+1-th dist.
            if (count >= k) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        
        // Why can return left here, but can't return mid in the while-loop ?
        // Ans: When mid gives at least k dist and left < mid, 
        //    then following steps push right(==mid) to left until left==right==mid with mid giving at least
        //    k dist.
        //    When mid does not give enough k dist, push left(=mid+1) to right until left==right with right==largest dist.
        return left;
    }
};

// Binary search, Two pointers