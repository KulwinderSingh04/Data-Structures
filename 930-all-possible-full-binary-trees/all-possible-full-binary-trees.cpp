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
    vector<TreeNode*> fun(int n, unordered_map<int,vector<TreeNode*>>& dp) {
        if(n % 2 == 0) return {};
        if(n == 1) {
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        if(dp.find(n) != dp.end()) return dp[n]; 
        vector<TreeNode*> ans;
        for(int i = 1; i < n; i += 2) {
            auto l = fun(i, dp);
            auto r = fun(n - i - 1, dp);
            for(int j1 = 0; j1 < l.size(); j1++) {
                for(int j2 = 0; j2 < r.size(); j2++) {
                    TreeNode* root = new TreeNode(0);
                    root -> left = l[j1];
                    root -> right = r[j2];
                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> dp;
        return fun(n, dp);
    }
};