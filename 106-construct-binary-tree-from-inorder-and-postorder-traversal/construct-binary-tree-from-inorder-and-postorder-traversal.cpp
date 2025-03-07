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
    TreeNode* fun(vector<int>& in,int si,int ei,vector<int>& post,int sp,int ep) {
        if(sp>ep) return NULL;
        TreeNode* root = new TreeNode(post[ep]);
        if(sp==ep) return root;
        for(int i=si;i<=ei;i++) {
            if(in[i]==post[ep]) {
                root->left = fun(in,si,i-1,post,sp,sp+i-si-1);
                root->right = fun(in,i+1,ei,post,sp+i-si,ep-1);
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        return fun(in,0,n-1,post,0,n-1);
    }
};