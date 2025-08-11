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
    vector<TreeNode*> fun(int l, int r, vector<int>& arr) {
        if(l > r) return {NULL};
        // if(l == r) return new TreeNode(arr[l]);
        vector<TreeNode*> ans;
        for(int i = l; i <= r; i++) {
            // TreeNode* root = new TreeNode(arr[i]);

            vector<TreeNode*> left = fun(l, i - 1, arr);
            vector<TreeNode*> right = fun(i + 1, r, arr);
            for(auto x : left) {
                for(auto y : right) {
                    TreeNode* node = new TreeNode(arr[i]);
                    node -> left = x;
                    node -> right = y;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> arr(n);
        for(int i = 0; i < n; i++) arr[i] = i + 1;
        return fun(0, n - 1, arr);
    }
};