class Node {
    public:
    bool flag;
    vector<Node*> links;
    Node() {
        flag = false;
        links.resize(10, NULL);
    }
};
class Solution {
    Node* root;
public:
    void insert(string word) {
        int n = word.size();
        Node* node = root;
        for(int i = 0; i < n; i++) {
            if(node -> links[word[i] - 48] == NULL) {
                node -> links[word[i] - 48] = new Node();
            }
            node = node -> links[word[i] - 48];
        }
        node -> flag = true;
    }
    void dfs(Node* node, string s, vector<int>& v) {
        if(node -> flag) {
            v.push_back(stoi(s));
        }
        for(int i = 0; i < 10; i++) {
            if(node -> links[i]) {
                s += i + 48;
                dfs(node -> links[i], s, v);
                s.pop_back();
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        root = new Node();
        for(int i = 1; i < n + 1; i++) {
            insert(to_string(i));
        }
        vector<int> v;
        dfs(root, "", v);
        return v;
    }
};