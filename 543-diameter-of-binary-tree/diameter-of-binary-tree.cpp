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
    int fun(TreeNode* root, int& mx) {
        if(root == NULL) return 0;
        int a = fun(root -> left, mx);
        int b = fun(root -> right, mx);
        mx = max(mx, a + b);
        return 1 + max(a, b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        fun(root, mx);
        return mx;
    }
};