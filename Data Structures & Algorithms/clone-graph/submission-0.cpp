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
public:
    Node* dfs(Node* node , unordered_map<Node*,Node*> &mp){
        if(!node)return node;
        if(mp.count(node))return mp[node];

        Node* cpy = new Node(node->val);
        mp[node] = cpy;

        for(auto& neighb : node->neighbors){
            cpy->neighbors.push_back(dfs(neighb,mp));
        }

        return cpy;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        return dfs(node,mp);
    }
};
