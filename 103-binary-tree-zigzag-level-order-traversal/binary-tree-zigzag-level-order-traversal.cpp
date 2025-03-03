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
    void fun(TreeNode* root, vector<vector<int>>& ans, int i, int n) {
        if(root == NULL) return;
        if(i == n) ans[i].push_back(root -> val);
        if(n % 2 == 0) {
            fun(root -> left, ans, i + 1, n);
            fun(root -> right, ans, i + 1, n);
        }
        else {
            fun(root -> right, ans, i + 1, n);
            fun(root -> left, ans, i + 1, n);
        }
    }
    void dis(TreeNode* root, vector<vector<int>>& ans) {
        for(int i = 0; i < ans.size(); i++) {
            fun(root, ans, 0, i);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int l = lvl(root);
        vector<vector<int>> ans(l);
        dis(root, ans);
        return ans;
    }
};