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
    int fun(TreeNode* root) {
        if(root == NULL) return 0;
        int a = fun(root -> left);
        int b = fun(root -> right);
        return a + b + root -> val;

    }
    int MOD = 1e9 + 7;
    int dfs(TreeNode* root, int& totSum, long long& ans) {
        if(root == NULL) return 0;
        int a = dfs(root -> left, totSum, ans);
        int b = dfs(root -> right, totSum, ans);
        long long sum = a + b + root -> val;
        ans = max(1LL * ans, sum * (totSum - sum));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int sum = fun(root);
        long long ans = 0;
        dfs(root, sum, ans);
        ans %= MOD;
        return ans;
    }
};