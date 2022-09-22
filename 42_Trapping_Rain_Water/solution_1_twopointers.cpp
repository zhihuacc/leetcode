class Solution {
public:
    int trap(vector<int>& height) {
        
        int left_max = 0, right_max = 0;
        int water_cap = 0;
        for (int n = height.size(), left = 0, right= n-1;
             left < right;) {
            
            if (height[left] < height[right]) {
                // 1) right_max >= height[right] > height[left]
                // 2.1) height[left-k1...left] < height[right]
                // 2.2) height[left-k2...left-k1] < height[right+k3]
                // 2.3) right_max >= height[right...]
                //    => left_max < right_max
                if (height[left] < left_max) {
                    
                    water_cap += left_max - height[left];
                } else {
                    left_max = height[left];
                }
                left++;
            } else {
            
                if (height[right] < right_max) {

                    water_cap += right_max - height[right];
                } else {
                    right_max = height[right];
                }
                right--;
            }
        }
        
        return water_cap;
    }
};