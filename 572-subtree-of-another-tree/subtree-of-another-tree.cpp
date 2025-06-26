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
    string fun(TreeNode* root) {
        if(root == NULL) return "X";
        string a = "";
        a += ( '(' + to_string(root -> val) + ')');
        string a1 = fun(root -> left);
        string a2 = fun(root -> right);
        a += '#' + a1 + '?' + a2;
        return a;
    }
    void lps(string& pat, vector<int>& v) {
        int n = pat.size();
        int len = 0;
        v[0] = 0;
        int i = 1;
        while(i < n) {
            if(pat[i] == pat[len]) {
                len++;
                v[i] = len;
                i++;
            } else {
                if(len == 0) {
                    i++;
                    v[i - 1] = 0;
                }
                else len = v[len - 1];
            }
        }
    }
    bool kmp(string& pat, string& txt) {
        // code here
        int n = txt.size();
        vector<int> v(pat.size());
        lps(pat, v);
        int i = 0;
        int j = 0;
        vector<int> res;
        while(i < txt.size()) {
            if(txt[i] == pat[j]) {
                i++;
                j++;
                if(j == pat.size()) {
                    return true;
                }
            }
            else {
                if(j != 0) j = v[j - 1];
                else i++;
            }
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = "", s2 = "";
        s1 = fun(root);
        s2 = fun(subRoot);
        cout << s1 << " " << s2 << endl;
        return kmp(s2, s1);
    }
};