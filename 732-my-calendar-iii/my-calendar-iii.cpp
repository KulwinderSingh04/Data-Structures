class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int ans = 0;
        int count = 0;
        for(auto x : mp) {
            count += x.second;
            ans = max(ans, count);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */