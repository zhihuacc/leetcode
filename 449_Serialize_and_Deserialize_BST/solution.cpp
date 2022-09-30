/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
    void pre_order_enc(TreeNode *root, string &enc) {
        
        if (root == nullptr)
            return;
        
        char *p = reinterpret_cast<char*>(&root->val);
        //WARN It's OK to insert byte 0, and the length is not determined by the first byte 0.
        enc.insert(enc.length(), p, 4);
        
        pre_order_enc(root->left, enc);
        pre_order_enc(root->right, enc);
        
    }
    
    TreeNode* pre_order_dec(string &enc, int &beg, int low_limit, int high_limit) {
        
        if (beg >= enc.length())
            return nullptr;
        
        int *pv = reinterpret_cast<int*>(enc.data() + beg);
        if (*pv < low_limit || *pv > high_limit)
            return nullptr;
        
        TreeNode *root = new TreeNode(*pv);
        
        beg += 4;
        root->left = pre_order_dec(enc, beg, low_limit, *pv);
        
        root->right = pre_order_dec(enc, beg, *pv, high_limit);
        
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string enc;
        pre_order_enc(root, enc);
        
        // No need to insert an '\0' at the end.
        // enc.push_back('\0');
        
        return enc;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        // data.pop_back();
        int beg = 0;
        return pre_order_dec(data, beg, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;