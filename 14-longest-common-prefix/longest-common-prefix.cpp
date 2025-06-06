class Node {
    public: 
    bool flag;
    vector<Node*> links;
    Node() {
        links.resize(26, NULL);
        flag = false;
    }
};

class Solution {
    Node* root;
public:
    void insert(string& str) {
        Node* node = root;
        int n = str.size();
        for(int i = 0; i < n; i++) {
            if(node -> links[str[i] - 97] == NULL) {
                node -> links[str[i] - 97] = new Node();
            }
            node = node -> links[str[i] - 97];
        }
        node -> flag = true;
    }
    int count() {
        int ans = 0;
        Node* node = root;
        while(1) {
            int count = 0;
            Node* t;
            for(int i = 0; i < 26; i++) {
                if(node -> links[i] != NULL) {
                    count++;
                    t = node -> links[i];
                }
            }
            if(count != 1) return ans;
            
            if(node -> flag) return ans;
            ans++;
            node = t;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        root = new Node();
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            insert(strs[i]);
        }
        int a = count();
        return strs[0].substr(0, a);

    }
};