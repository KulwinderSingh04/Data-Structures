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
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* root = new Node(node -> val);
        queue<pair<Node*, Node*>> q;
        q.push({root, node});
        vector<Node*> nodeRegister(101, NULL); 
        unordered_set<Node*> st;
        nodeRegister[node -> val] = root;
        st.insert(node);
        while(q.size()) {
            auto t = q.front();
            q.pop();
            auto r = t.first;
            auto n = t.second;
            for(auto x : n -> neighbors) {
                
                if(nodeRegister[x -> val]) {
                    r -> neighbors.push_back(nodeRegister[x -> val]);
                    
                }
                else {
                    Node* newNode = new Node(x -> val);
                    r -> neighbors.push_back(newNode);
                    nodeRegister[x -> val] = newNode;
                    q.push({newNode, x});
                }
                st.insert(x);
            }
        }
        return root;
        
    }
};