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
    bool fun(TreeNode* root, TreeNode*& prev, int& count) {
        if(root == NULL) return false;
        bool a = fun(root -> left, prev, count);
        if(a) return a;
        count++;
        if(prev && prev -> val >= root -> val) return true;
        prev = root;
        bool b = fun(root -> right, prev, count);
        if(b) return b;
        return false;
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> m;
        int count = 0;
        for(auto node : trees) {
            if(node -> left == NULL && node -> right == NULL) {
                count++;
                // m[node -> val] = node;
            }
            else {
                count++;
                if(node -> left) {
                    count++;
                    m[node -> left -> val] = node -> left;
                }
                if(node -> right) {
                    count++;
                    m[node -> right -> val] = node -> right;
                }
            }
        }
        int n = trees.size();
        TreeNode* root = NULL;

        for(int i = 0; i < n; i++) {
            if(m.find(trees[i] -> val) != m.end()) {
                if(trees[i] -> left) m[trees[i] -> val] -> left = trees[i] -> left;
                if(trees[i] -> right) m[trees[i] -> val] -> right = trees[i] -> right;
            } else if(root == NULL) {
                root = trees[i];
            } else {
                return NULL;
            }
        }
        TreeNode* prev = NULL;
        int c = 0;
        if(fun(root, prev, c)) return NULL;
        if(c != count - n + 1) return NULL;
        return root;
    }
};