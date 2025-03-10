class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int> nextCon(n);
        int idx = n;
        for(int i = n - 1; i >= 0; i--) {
            nextCon[i] = idx;
            if(isVowel(word[i]) == false) idx = i;
        }
        int i = 0; 
        int j = 0;
        int t = 0;
        long long ans = 0;
        unordered_map<char, int> m;
        int con = 0;
        while(j < n) {
            if(isVowel(word[j])) {
                m[word[j]]++;
            }
            else t++;
            while(t > k) {
                if(isVowel(word[i])) {
                    m[word[i]]--;
                    if(m[word[i]] == 0) m.erase(word[i]);
                }
                else t--;
                i++;
            }

            while(m.size() == 5 && t == k) {
                ans += nextCon[j] - j;
                if(isVowel(word[i])) {
                    m[word[i]]--;
                    if(m[word[i]] == 0) m.erase(word[i]);
                }
                else t--;
                i++;
            }

            j++;
        }
        return ans;
    }
};