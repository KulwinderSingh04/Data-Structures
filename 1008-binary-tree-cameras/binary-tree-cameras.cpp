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
    int fun(TreeNode* root, int& ans) {
        if(root == NULL) return 0;
        if((root -> left == NULL && root -> right == NULL)) return 1;
        int a = fun(root -> left, ans);
        int b = fun(root -> right, ans);
        if(a == 1 || b == 1) {
            ans++;
            return 2;
        }
        if(a == 2 || b == 2) return 0;
        return 1;

    }
    int minCameraCover(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL) return 1;
        int ans = 0;
        int t = fun(root, ans);
        if(t == 1) ans++; 
        return ans;
    }
};