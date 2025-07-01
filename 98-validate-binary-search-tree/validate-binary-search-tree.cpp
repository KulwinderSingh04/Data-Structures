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
    void fun(TreeNode*& prev, TreeNode* root, bool& ans) {
        if(root == NULL) return;
        fun(prev, root -> left, ans);
        if(prev && prev -> val >= root -> val) {
            ans = false;
        }
        prev = root;
        fun(prev, root -> right, ans);

    }
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        TreeNode* prev = NULL;
        fun(prev, root, ans);
        return ans;
    }
};