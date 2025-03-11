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
    long long fun1(TreeNode* root) {
        if(root == NULL) return LLONG_MIN;
        return max((long long)root -> val, max(fun1(root -> left), fun1(root -> right)));
    }
    long long fun2(TreeNode* root) {
        if(root == NULL) return LLONG_MAX;
        return min((long long)root -> val, min(fun2(root -> left), fun2(root -> right)));
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        long long pred = fun1(root -> left);
        long long succ = fun2(root -> right);
        if(pred >= root -> val || succ <= root -> val) return false;
        bool a = isValidBST(root -> left);
        bool b = isValidBST(root -> right);
        return a && b;
    }
};