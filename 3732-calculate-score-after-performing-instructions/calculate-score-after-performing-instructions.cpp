class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        int i = 0;
        long long score = 0;
        while( i >= 0 && i < n) {
            if(instructions[i] == "add") {
                if(values[i] == INT_MIN) break;
                score += values[i];
                values[i] = INT_MIN;
                i++;
            }
            else {
                
                if(values[i] == INT_MIN || values[i] == 0) break;
                int idx = i; 
                i += values[i];
                values[idx] = INT_MIN;
            }
        }
        return score;
    }
};