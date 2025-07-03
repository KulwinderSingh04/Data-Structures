class Solution {
public:
    char kthCharacter(int k) {
        string a = "a";
        while(a.size() < k) {
            string str = "";
            for(int i = 0; i < a.size(); i++) {
                if(a[i] == 'z') str += 'a';
                else str += a[i] + 1;
            }
            a += str;
        }
        return a[k - 1];
    }
};