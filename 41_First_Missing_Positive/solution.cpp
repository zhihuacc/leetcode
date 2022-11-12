class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        int n = arr.size();
        for(int i = 0; i < n;){
            
            if( arr[i] <= n && arr[i] > 0 && arr[i] != arr[arr[i] - 1]){
                // 1) Don't care 0 and numbers beyond n
                // 2) put arr[i] in [1,n] into arr[arr[i]-1] , i.e., rearrange to ensure arr[j] == j+1 for those numbers
                swap(arr[i], arr[arr[i] - 1]);
            }
            else{
                i++;
            }
        }
        
        for(int i = 0 ; i< n; i++){
            if(arr[i] != i + 1){
                return i + 1;
            }
        }
        
        return n + 1;
    }
};

// https://leetcode.com/problems/first-missing-positive/