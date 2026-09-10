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
    pair<int, int> fun(TreeNode* root, int& ans) {
        if(root == NULL) return {0, 0};
        auto l = fun(root -> left, ans);
        auto r = fun(root -> right, ans);
        int cnt = l.second + r.second + 1;
        int sum = l.first + r.first + root -> val;
        if(root -> val == sum / cnt) ans++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        fun(root, cnt);
        return cnt;
    }
};