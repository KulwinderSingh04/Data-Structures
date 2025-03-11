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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root -> val == key) {
            if(root -> left && root -> right) {
                TreeNode* pred = root -> left;
                while(pred -> right) pred = pred -> right;
                swap(root -> val, pred -> val);
                root -> left = deleteNode(root -> left, key);
                return root;
            }
            else {
                if(root -> left) {
                    return root -> left;
                }
                else {
                    return root -> right;
                }
            }
        }
        if(root -> val > key) root -> left = deleteNode(root -> left, key);
        else root -> right = deleteNode(root -> right, key);
        return root;
    }
};