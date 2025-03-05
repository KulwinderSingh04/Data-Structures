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
    int lvl(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(lvl(root -> left), lvl(root -> right));
    }
    void fun(TreeNode* root, int i, vector<int>& ans) {
        if(root == NULL) return;
        ans[i] = root -> val;
        fun(root -> left, i + 1, ans);
        fun(root -> right, i + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int l = lvl(root);
        vector<int> ans(l);
        fun(root, 0, ans);
        return ans;
    }
};