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
    TreeNode* fun(vector<int>& pre, int prelo, int prehi, vector<int>& in, int inlo, int inhi) {
        if(prelo > prehi) return NULL;
        if(prelo == prehi) return new TreeNode(pre[prelo]);
        TreeNode* root = new TreeNode(pre[prelo]);
        int idx = -1;
        for(int i = inlo; i < inhi + 1; i++) {
            if(in[i] == pre[prelo]) {
                idx = i;
                break;
            }
        }
        root -> left = fun(pre, prelo + 1, prelo + idx - inlo, in, inlo, idx - 1);
        root -> right = fun(pre,prelo + idx - inlo + 1, prehi, in, idx + 1, inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return fun(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};