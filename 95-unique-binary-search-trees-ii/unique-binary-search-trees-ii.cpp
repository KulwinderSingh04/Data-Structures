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
    vector<TreeNode*> fun(int l, int r, vector<int>& arr, unordered_map<string, vector<TreeNode*>>& dp) {
        if(l > r) return {NULL};
        if(l == r) return {new TreeNode(arr[l])};
        string str = to_string(l) + "_" + to_string(r);
        if(dp.find(str) != dp.end()) return dp[str];
        vector<TreeNode*> ans;
        for(int i = l; i <= r; i++) {

            vector<TreeNode*> left = fun(l, i - 1, arr, dp);
            vector<TreeNode*> right = fun(i + 1, r, arr, dp);
            for(auto x : left) {
                for(auto y : right) {
                    TreeNode* node = new TreeNode(arr[i]);
                    node -> left = x;
                    node -> right = y;
                    ans.push_back(node);
                }
            }
        }
        return dp[str] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> arr(n);
        for(int i = 0; i < n; i++) arr[i] = i + 1;
        unordered_map<string, vector<TreeNode*>> dp;
        return fun(0, n - 1, arr, dp);
    }
};