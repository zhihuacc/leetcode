class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> res;
        for (int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size(); 
             i < n1 && j < n2;) {
            
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};