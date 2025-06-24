class Solution {
public:
    char fun(vector<char>& v, char op) {
        // cout << op << " -> ";
        int n = v.size();
        // for(int i = 0; i < n; i++) cout << v[i] << ", ";
        // cout << endl;
        if(op == '&') {
            for(int i = 0; i < n; i++) {
                if(v[i] == 'f') return 'f';
            }
            return 't';

        } else if(op == '|') {
            for(int i = 0; i < n; i++) {
                if(v[i] == 't') return 't';
            }
            return 'f';
        } else {
            if(v[0] == 'f') return 't';
            else return 'f';
        }
    }
    bool parseBoolExpr(string exp) {
        stack<char> op;
        stack<char> ch;
        for(int i = 0; i < exp.size(); i++) {
            if(exp[i] == ',') continue;
            if(exp[i] == '&' || exp[i] == '|' || exp[i] == '!') {
                op.push(exp[i]);
            } else {
                if(exp[i] != ')') {
                    ch.push(exp[i]);
                } else {
                    vector<char> v;
                    while(ch.top() != '(') {
                        v.push_back(ch.top());
                        ch.pop();
                    }
                    ch.pop();
                    char opr = op.top();
                    op.pop();
                    char ans = fun(v, opr);
                    // cout << ans << " ";
                    ch.push(ans);
                }
            }
        }
        return ch.top() == 't';
    }
};