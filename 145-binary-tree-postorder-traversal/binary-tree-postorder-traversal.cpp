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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(!root) return {};
        st.push(root);
        vector<int> v;
        while(st.size()) {
            auto t = st.top();
            st.pop();
            v.push_back(t -> val);
            if(t -> left) st.push(t -> left);
            if(t -> right) st.push(t -> right);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};