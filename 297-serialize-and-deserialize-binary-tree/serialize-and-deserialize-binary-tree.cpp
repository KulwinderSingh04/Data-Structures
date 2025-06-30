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
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        while(q.size()) {
            auto t = q.front();
            q.pop();
            if(t) ans += to_string(t -> val) + ",";
            else ans += "N,";
            if(t) q.push(t -> left);
            if(t) q.push(t -> right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << data << " ";
        if(data == "N,") return NULL;
        queue<TreeNode*> q;
        string num = "";
        int i = 0;
        while(data[i] != ',') i++;
        TreeNode* root = new TreeNode(stoi(data.substr(0, i)));
        // cout << root -> val << " ";
        i++;
        q.push(root);
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int j = i;
            while(data[j] != ',') j++;

            string a = data.substr(i , j - i);
            // cout << a << " ";
            if(a != "N") {
                // cout << a << " ";
                t -> left = new TreeNode(stoi(a));
            }
            else t -> left = NULL;
            i = j + 1;
            j++;
            while(data[j] != ',') j++;
            a = data.substr(i, j - i);
            // cout << 1 << a << " ";
            if(a != "N") t -> right = new TreeNode(stoi(a));
            else t -> right = NULL;
            i = j + 1;
            if(t -> left) q.push(t -> left);
            if(t -> right) q.push(t -> right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));