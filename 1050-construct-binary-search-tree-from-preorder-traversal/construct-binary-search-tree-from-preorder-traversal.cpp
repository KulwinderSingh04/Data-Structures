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
    TreeNode* fun(vector<int>& v, int lo, int hi) {
        if(lo > hi) return NULL;
        if(lo == hi) return new TreeNode(v[lo]);
        TreeNode* root = new TreeNode(v[lo]);
        int idx = hi + 1;
        for(int i = lo + 1; i <= hi; i++) {
            if(v[i] > v[lo]) {
                idx = i;
                break;
            }
        }
        root -> left = fun(v, lo + 1, idx - 1);
        root -> right = fun(v, idx, hi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return fun(preorder, 0, n - 1);
    }
};