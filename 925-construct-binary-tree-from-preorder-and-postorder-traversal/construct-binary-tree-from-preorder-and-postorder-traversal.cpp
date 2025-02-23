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
    TreeNode* fun(vector<int>& pre, int prei, int prej, vector<int>& post, int posi, int posj) {
        if(prei > prej) return NULL;
        if(prei == prej) return new TreeNode(pre[prej]);
        TreeNode* root = new TreeNode(pre[prei]);
        int dis = 0;
        for(int i = posi; i <= posj; i++) {
            if(post[i] == pre[prei + 1]) {
                dis = i - posi;
                break;
            }
        }
        root -> left = fun(pre, prei + 1, prei + 1 + dis, post, posi, posi + dis);
        root -> right = fun(pre, prei + dis + 2, prej, post, posi + dis + 1 , posj - 1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        return fun(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};