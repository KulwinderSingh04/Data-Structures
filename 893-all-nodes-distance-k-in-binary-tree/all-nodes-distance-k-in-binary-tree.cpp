/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m) {
        if(root == NULL) return;
        if(root -> left) m[root -> left] = root;
        if(root -> right) m[root -> right] = root;
        fun(root -> left, m);
        fun(root -> right, m);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> m;
        fun(root, m);
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({target, k});
        unordered_set<TreeNode*> s;
        s.insert(target);
        while(q.size()) {
            auto t = q.front();
            q.pop();
            cout << t.first -> val << " ";
            if(t.second == 0) ans.push_back(t.first -> val);
            if(t.second < 0) break;
            if(t.first -> left && s.find(t.first -> left) == s.end()) {
                q.push({t.first -> left, t.second - 1});
                s.insert(t.first -> left);
            }
            if(t.first -> right && s.find(t.first -> right) == s.end()) {
                q.push({t.first -> right, t.second - 1});
                s.insert(t.first -> right);
            }
            if(m.find(t.first) != m.end() && s.find(m[t.first]) == s.end()) {
                q.push({m[t.first], t.second - 1});
                // m.erase(t.first);
                s.insert(m[t.first]);
            }
        }
        return ans;
    }
};