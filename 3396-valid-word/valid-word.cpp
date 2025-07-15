class Solution {
public:
    bool isDigit(char x) {
        return x >= '0' && x <= '9';
    }

    bool isEnglish(char x) {
        return (x >= 65 && x <= 92) || (x >= 97 && x <= 122);
    }
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int c = 0, v = 0;
        for(auto x : word) {
            if(!isDigit(x) && !isEnglish(x)) return false;
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') v++;
            else if(isEnglish(x)) c++;
        }
        return v >= 1 && c >= 1;
    }
};