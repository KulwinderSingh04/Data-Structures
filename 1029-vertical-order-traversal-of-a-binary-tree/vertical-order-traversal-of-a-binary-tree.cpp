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
    void fun(TreeNode* root, int hr, int vr, map<int, map<int, vector<int>>>& m) {
        if(root == NULL) return;
        m[vr][hr].push_back(root -> val);
        fun(root -> left, hr + 1, vr - 1, m);
        fun(root -> right, hr + 1, vr + 1, m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> m;
        fun(root, 0, 0, m);
        for(auto x : m) {
            auto t = x.second;
            vector<int> a;
            for(auto s : t) {
                vector<int> v = s.second;
                sort(v.begin(), v.end());
                a.insert(a.end(), v.begin(), v.end());
            }
            ans.push_back(a);
        }
        return ans;
    }
};