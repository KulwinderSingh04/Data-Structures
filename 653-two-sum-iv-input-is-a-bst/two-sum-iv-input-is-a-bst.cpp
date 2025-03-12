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
class BSTIterater {
    public : 
    stack<TreeNode*>  st;
    bool rev;
    BSTIterater(TreeNode* root, bool rev) {
        this -> rev = rev;
        fun(root);
    }
    void fun(TreeNode* root) {
        while(root) {
            st.push(root);
            if(rev) {
                root = root -> right;
            }
            else root = root -> left;
        }
    }
    bool hasNext() {
        return st.size();
    }
    int next() {
        auto t = st.top();
        st.pop();
        if(rev) fun(t -> left);
        else fun(t -> right);
        return t -> val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterater a(root, false);
        BSTIterater b(root, true);
        int i = a.next();
        int j = b.next();
        while(i < j) {
            if(i + j == k) return true;
            else if(i + j < k) i = a.next();
            else j = b.next();
        }
        return false;
    }
};