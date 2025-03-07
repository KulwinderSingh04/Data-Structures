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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            auto t = q.front();
            q.pop();
            if(t) s += to_string(t -> val) + ",";
            else s += "#,";
            if(t) q.push(t -> left);
            if(t) q.push(t -> right);
        }
        cout << s << " ";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s[0] == '#') return NULL;
        vector<TreeNode*> ans;
        int n = s.size();
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == ',') {
                string sub = s.substr(j, i - j);
                j = i + 1;
                if(sub != "#") ans.push_back(new TreeNode(stoi(sub)));
                else ans.push_back(NULL);
            }
        }
        queue<TreeNode*> q;
        q.push(ans[0]);
        int i = 1;
        while(q.size() && i < ans.size()) {
            auto t = q.front();
            q.pop();
            t -> left = ans[i];
            i++;
            if(i >= ans.size()) break;
            t -> right = ans[i];
            i++;
            if(t -> left) q.push(t -> left);
            if(t -> right) q.push(t -> right);
        }
        return ans[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));