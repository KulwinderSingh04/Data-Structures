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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long mx = 1;
        while(q.size()) {
            long long s = q.size();
            long long f = -1, l = -1;
            long long mn = q.front().second;
            for(long long i = 0; i < s; i++) {
                auto t = q.front();
                q.pop();
                long long m = t.second - mn;
                if(f == -1) f = t.second;
                else l = t.second;
                if(t.first -> left) {
                    q.push({t.first -> left, 2 * m + 1});
                }
                if(t.first -> right) {
                    q.push({t.first -> right, 2 * m + 2});
                }
            }
            mx = max(mx, l - f + 1);
        }
        return mx;
    }
};