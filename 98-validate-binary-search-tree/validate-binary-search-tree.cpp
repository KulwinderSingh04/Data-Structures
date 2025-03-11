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
    bool fun(TreeNode* root, long long mn, long long mx) {
        if(root == NULL) return true;
        if(!(root -> val < mx && root -> val > mn)) return false;
        bool a = fun(root -> left, mn, root -> val);
        bool b = fun(root -> right, root -> val, mx);
        return a && b;
    }
    bool isValidBST(TreeNode* root) {
        return fun(root, LLONG_MIN, LLONG_MAX);
    }
};