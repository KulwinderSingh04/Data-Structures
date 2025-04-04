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
    void fun(TreeNode* root, unordered_map<int, int>& m, int d,int& mxDepth) {
        if(root == NULL) return;
        m[root -> val] = d;
        mxDepth = max(mxDepth, d);
        fun(root -> left, m, d + 1, mxDepth);
        fun(root -> right, m, d + 1, mxDepth);
    }
    TreeNode* lca(TreeNode* root, unordered_map<int, int>& m,int mx) {
        if(root == NULL) return NULL;
        if(m[root -> val] == mx) return root;
        TreeNode* left = lca(root -> left, m, mx);
        TreeNode* right = lca(root -> right, m, mx);
        if(left && right) return root;
        if(left) return left;
        return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int , int> m;
        int mxDepth = 0;
        fun(root, m, 0, mxDepth);
        return lca(root, m, mxDepth);

    }
};