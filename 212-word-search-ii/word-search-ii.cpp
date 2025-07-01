
class Node {
    public :
    bool flag;
    string str;
    vector<Node*> links;
    Node() {
        flag = false;
        str = "";
        links.resize(26, NULL);
    }
};
class Solution {
public:
    Node* root;
    void insert(string& word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node -> links[word[i] - 97] == NULL) {
                node -> links[word[i] - 97] = new Node();
            }
            // string s = node -> str;
            node = node -> links[word[i] - 97];
            // node -> str = s;
            // node -> str.push_back(word[i] - 97);
        }
        node -> flag = true;
        node -> str = word;
    }
    void fun(int i, int j, vector<vector<char>>& board, vector<string>& ans, Node* node) {
        int n = board.size();
        int m = board[0].size();
        if(node && node -> flag) {
            // cout << "yes" << endl;
            ans.push_back(node -> str);
            node -> flag = false;
        }
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '.') return;
        
        if(node && node -> links[board[i][j] - 97]) {
            char ch = board[i][j];
            node = node -> links[board[i][j] - 97];
            board[i][j] = '.';
            fun(i - 1, j, board, ans, node);
            fun(i + 1, j, board, ans, node);
            fun(i, j - 1, board, ans, node);
            fun(i, j + 1, board, ans, node);
            board[i][j] = ch;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        for(auto x : words) insert(x);
        vector<string> ans;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                Node* node = root;
                fun(i, j, board, ans, node);
            }
        }
        return ans;
    }
};