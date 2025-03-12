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
    bool fun(TreeNode* root, int k, unordered_set<int>& s) {
        if(root == NULL) return false;
        if(s.find(k - root -> val) != s.end()) return true;
        s.insert(root -> val);
        bool a = fun(root -> left, k, s);
        bool b = fun(root -> right, k, s);
        return a || b;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return fun(root, k, s);
    }
};