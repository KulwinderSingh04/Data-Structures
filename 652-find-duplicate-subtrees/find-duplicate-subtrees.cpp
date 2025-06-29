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
    string fun(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& v) {
        if(root == NULL) {
            return "N,";
        }
        string l = fun(root -> left, m, v);
        string r = fun(root -> right, m, v);
        string s = to_string(root -> val) + "," + l + r;
        if(m.find(s) != m.end() && m[s] == 1) {
            v.push_back(root);
            m[s] = 0;
        }
        if(m.find(s) == m.end()) m[s] = 1;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*> v;
        fun(root, m , v);
        return v;
    }
};