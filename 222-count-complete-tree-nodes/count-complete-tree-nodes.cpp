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
    int lHeight(TreeNode* root) {
        int ht = 0;
        while(root) {
            root = root -> left;
            ht++;
        }
        return ht;
    }
    int rHeight(TreeNode* root) {
        int ht = 0;
        while(root) {
            root = root -> right;
            ht++;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int l = lHeight(root);
        int r = rHeight(root);
        if(l == r) return pow(2, l) - 1;
        int left = countNodes(root -> left);
        int right = countNodes(root -> right);
        return 1 + left + right;
    }
};