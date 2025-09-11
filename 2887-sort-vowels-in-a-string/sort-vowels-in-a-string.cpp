class Solution {
public:
    string sortVowels(string s) {
        string a = "";
        for(auto x : s) {
            if(x == 'a' || x == 'e' || x == 'i' || x =='o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x =='O' || x == 'U') {
                a += x;
            }
        }
        int i = 0;
        sort(a.begin(), a.end());
        for(auto& x : s) {
            if(x == 'a' || x == 'e' || x == 'i' || x =='o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x =='O' || x == 'U') {
                x = a[i++];
            }
        }
        return s;
    }
};