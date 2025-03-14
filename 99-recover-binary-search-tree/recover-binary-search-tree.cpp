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
    void inorder(TreeNode* root,TreeNode*& prev, TreeNode*& first, TreeNode*& middle, TreeNode*& last) {
        if(root == NULL) {
            return;
        }
        if(root -> left) inorder(root -> left, prev, first, middle, last);
        if(prev && root -> val < prev -> val) {
            if(first == NULL) {
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        if(root -> right) inorder(root -> right, prev, first, middle, last);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first, *middle, *last, *prev;
        first = middle = last = prev = NULL;
        inorder(root, prev, first, middle, last);
        if(last == NULL) swap(first -> val, middle -> val);
        else swap(first -> val, last -> val);
    }
};