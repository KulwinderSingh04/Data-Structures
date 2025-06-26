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
    bool fun(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        if(root1 -> val != root2 -> val) return false;
        bool a = fun(root1 -> left, root2 -> left);
        bool b = fun(root1 -> right, root2 -> right);
        return a && b;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(root -> val == subRoot -> val && fun(root, subRoot)) return true;
        bool a = isSubtree(root -> left, subRoot);
        bool b = isSubtree(root -> right, subRoot);
        return a || b;
    }
};