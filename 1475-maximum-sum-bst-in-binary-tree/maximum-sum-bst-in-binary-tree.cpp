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
    vector<int> fun(TreeNode* root, int& res) {
        if(root == NULL) return {0, INT_MIN, INT_MAX};

        auto left = fun(root -> left, res);
        auto right = fun(root -> right, res);
        if(root -> val > left[1] && root -> val < right[2]) {
            int ans = left[0] + root -> val + right[0];
            res = max(res, ans);
            return {ans, max(right[1], root -> val), min(left[2], root -> val)};
        } else {
            return {max(left[0], right[0]), INT_MAX, INT_MIN};
        }
    }
    int maxSumBST(TreeNode* root) {
        int res = 0;
        fun(root, res);
        return res;
    }
};