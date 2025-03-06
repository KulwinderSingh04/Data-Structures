/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m, int start, TreeNode*& init) {
        if(root == NULL) return;
        if(root -> left) m[root -> left] = root;
        if(root -> right) m[root -> right] = root;
        if(root -> val == start) init = root;
        fun(root -> left, m, start, init);
        fun(root -> right, m, start, init);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> m;
        TreeNode* target = NULL;
        fun(root, m, start, target);
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        unordered_set<TreeNode*> s;
        s.insert(target);
        int ans = 0;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            ans = t.second;
            if(t.first -> left && s.find(t.first -> left) == s.end()) {
                q.push({t.first -> left, t.second + 1});
                s.insert(t.first -> left);
            }
            if(t.first -> right && s.find(t.first -> right) == s.end()) {
                q.push({t.first -> right, t.second + 1});
                s.insert(t.first -> right);
            }
            if(m.find(t.first) != m.end() && s.find(m[t.first]) == s.end()) {
                q.push({m[t.first], t.second + 1});
                s.insert(m[t.first]);
            }
        }
        return ans;
    }
};