class Solution {
    
    // NOTE: this gives avg btw nums[x] and [y-1], inclusive.
    double slope(const vector<int> &pre_sums, int x, int y) {
        
        return double(pre_sums[y] - pre_sums[x]) / (y-x);
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> pre_sums(n+1, 0);
        
        for (int i = 0; i < n; ++i) {
            pre_sums[i+1] = pre_sums[i] + nums[i];
        }
        
        if (n == k)
            return double(pre_sums[k]) / k;
        
        double max_avg = std::numeric_limits<double>::min();
        std::deque<int> hull;
        for (int i = k; i <= n; ++i) {
            // Start calculating max avg of intervals ending with i-1.
            
            // 1). Identify points on the hull from i-k-1 back to 0.
            while (hull.size() >= 2) {
                
                int last1 = hull.back();
                hull.pop_back();
                
                int last2 = hull.back();
                
                double d1 = slope(pre_sums, last1, last2);
                double d2 = slope(pre_sums, i-k, last2); 
                if (d1 <= d2) {
                    // The curve last2 -> last1 -> i-k+1 is convex, put last1 back to hull.
                    hull.push_back(last1);
                    break;
                }
                // The curve last2 -> last1 -> j-k is is NOT convex, remove last1
            }
            
            hull.push_back(i-k);
            
            // Identify max slope from i-1 to points on the hull,
            //   i.e., find tangent point on the hull with i-1.
            while (hull.size() >= 2) {
                
                int first1 = hull.front();
                hull.pop_front();
                
                int first2 = hull.front();
                double d1 = slope(pre_sums, first2, first1);
                double d2 = slope(pre_sums,  i, first1);
                if (d1 < d2) {
                   continue;
                } else {
                    // first1 is the tangent point.
                    // NOTE: the angle btw first2->first1 and i->first1 jumps from one sign to another,
                    //  so the tangent point must be btw current first1 and the previous first1.
                    hull.push_front(first1);
                    break;
                }
            }
            
            double avg = slope(pre_sums, i, hull.front());
            max_avg = std::max(max_avg, avg);
        }
        
        return max_avg;
    }
};

// Convex hull technique, this approach can give exact answer.