/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exist(TreeNode* root, TreeNode* p) {
        if(root == NULL) return false;
        if(root == p) return true;
        bool a = exist(root -> left, p);
        bool b = exist(root -> right, p);
        return a || b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        if(exist(root -> left, p) && exist(root -> right, q)) return root;
        if(exist(root -> right, p) && exist(root -> left, q)) return root;
        else if(exist(root -> right, p) && exist(root -> right, q)) return lowestCommonAncestor(root -> right, p, q);
        else return lowestCommonAncestor(root -> left, p, q);
    }
};