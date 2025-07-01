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
    TreeNode* fun(vector<int>& pre, int lo, int hi) {
        if(lo > hi) return NULL;
        TreeNode* root = new TreeNode(pre[lo]);
        int idx = hi;
        for(int i = lo + 1; i <= hi; i++) {
            if(pre[i] > pre[lo]) {
                idx = i - 1;
                break;
            }
        }
        root -> left = fun(pre, lo + 1, idx);
        root -> right = fun(pre, idx + 1, hi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return fun(preorder, 0, n - 1);
    }
};