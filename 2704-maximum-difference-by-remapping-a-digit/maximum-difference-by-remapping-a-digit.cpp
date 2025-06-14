class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string a1 = str;
        int n = str.size();
        // while(str[0] == '9') str.erase(str.begin());
        char ele = '9';
        for(int i = 0; i < n; i++) {
            if(str[i] != '9') {
                ele = str[i];
                break;
            }
        }
        string x1 = "", x2 = "";
        for(auto x : str) {
            if(x == ele) x1.push_back('9');
            else x1.push_back(x);
        }

        for(int i = n - 1; i >= 0; i--) {
            if(str[i] != str[0]) x2.push_back(str[i]);
            else x2.push_back('0');
        }
        // cout << x2 << " ";
        reverse(x2.begin(), x2.end());
        // cout << x2 << " ";
        // cout << stoi(x1) << " " << stoi(x2) << endl;
        return stoi(x1) - stoi(x2);
    }
};