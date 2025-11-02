class Solution {
public:
    // bool isPal(string& temp) {
    //     int i = 0;
    //     int j = temp.size() - 1;
    //     while(i < j) {
    //         if(temp[i] != temp[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    void fun(string& temp, int take, string& s, vector<int>& v, string& target, string& mid, string& ans) {
        if(temp.size() == target.size() / 2) { 
            string a = temp;
            reverse(a.begin(), a.end());
            a = temp + mid + a;
            if(a > target) ans = a;
            return;
        }

        int idx = temp.size();

        for(int i = 0; i < 26; i++) {
            if(v[i] == 0) continue;
            if(!take && i + 'a' < target[idx]) continue;
            temp.push_back(i + 'a');
            v[i]--;
            int newTake = take || (i + 'a' > target[idx]);
            fun(temp, newTake, s, v, target, mid, ans);
            if(ans != "") return;
            v[i]++;
            temp.pop_back();
        }
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int> v(26);
        int n = s.size();
        for(auto x : s) {
            v[x - 'a']++;
        }
        string mid = "";
        for(int i = 0; i < 26; i++) {
            if(v[i] % 2) {
                if(mid != "") return "";
                else mid += i + 'a';
            }
            v[i] /= 2;
        }
        string ans = ""; 
        string temp = "";
        fun(temp, 0, s, v, target, mid, ans);
        return ans;
    }
};