class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        
        stack<int> st;
        int low_bound = INT_MIN;
        
        for (auto i: preorder) {
            
            if (i <= low_bound)
                return false;
            
            while (!st.empty() && i > st.top()) {
                // If i > st.top(), i should be a right child node of a node in st.
                
                low_bound = st.top();
                // Popping st.top() means return from visiting of all left chilren of st.top() and itself.
                st.pop();  // pop() return void
            }
            // At the moment, low_bound is the parent of i and st.top() is parent of low_bound.
            // Pushing i into st means visiting left children of st.top()
            st.push(i);
        }
        
        return true;
    }
};