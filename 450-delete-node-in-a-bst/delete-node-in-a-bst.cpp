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
            if(root -> left == NULL && root -> right == NULL) return NULL;
            else if(root -> left == NULL || root -> right == NULL) {
                if(root -> left) return root -> left;
                return root -> right;
            } else {
                TreeNode* pred = root -> left;
                while(pred -> right) pred = pred -> right;
                swap(pred -> val, root -> val);
            }
        }
        root -> left = deleteNode(root -> left, key);
        root -> right = deleteNode(root -> right, key);
        return root;
    }
};