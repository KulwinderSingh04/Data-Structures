class Solution {
public:
    bool checkValidString(string s) {
        stack<int> br, ast;
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') br.push(i);
            else if(s[i] == ')') {
                if(br.size()) br.pop();
                else {
                    if(ast.size() == 0) return false;
                    else {
                        if(ast.top() < i) ast.pop();
                        else return false;
                    }
                }
            } else {
                ast.push(i);
            }
        }
        if(br.size() > ast.size()) return false;
        while(br.size()) {
            if(br.top() > ast.top()) return false;
            ast.pop();
            br.pop();
        }
        return true;
    }
};