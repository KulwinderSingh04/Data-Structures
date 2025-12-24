class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int sum = 0;
        for(auto x : apple) {
            sum += x;
        }
        sort(capacity.begin(), capacity.end(), greater<int> ());
        int count = 0;
        for(auto x : capacity) {
            sum -= x;
            count++;
            if(sum <= 0) return count;
        }
        return -1;
    }
};