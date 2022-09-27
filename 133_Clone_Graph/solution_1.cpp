/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
    Node *dfs(Node *node, unordered_map<Node*, Node*> &visited) {
        
        if (node == nullptr)
            return nullptr;
        
        auto it = visited.find(node);
        if (it != visited.end())
            return it->second;
        
        Node *copy = new Node(node->val);
        // WARN: visited need be updated before do dfs,
        //   otherwise, the stack may overflow.
        visited[node] = copy;
        
        for (auto nb: node->neighbors) {
            
            copy->neighbors.push_back(dfs(nb, visited));
        }
        
        
        return copy;
    }
public:
    Node* cloneGraph(Node* node) {
        
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }
};