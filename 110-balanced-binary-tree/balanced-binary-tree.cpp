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
    int fun(TreeNode* root, bool& flag) {
        if(root == NULL) return 0;
        if(flag == false) return 0;
        int l = fun(root -> left, flag);
        int r = fun(root -> right, flag);
        if(abs(l - r) > 1) {
            flag = false;
            return 0;
        }
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        fun(root, flag);
        return flag;
    }
};