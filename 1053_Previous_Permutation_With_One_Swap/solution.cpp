class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        
        for (int n = arr.size(), i = n-1; i > 0; i--){
            
            if (arr[i-1] > arr[i]) {
                // i-1
                for (int j = n-1; j >= i-1; j--) {
                    // arr[j-1] != arr[j] to make sure choose the leftmost one if duplicates exist.
                    // becasuse largest one is wanted.
                    //   e.g. [3,1,1,3] -> [1,3,1,3] instead of [1,1,3,3]
                    if (arr[j] < arr[i-1] && arr[j-1] != arr[j]) {
                        // j
                        swap(arr[j], arr[i-1]);
                        return arr;
                    }
                }
            }
        }
        
        return arr;
    }
};