class Solution {
public:
    bool fun1(vector<int> v) {
        if(v[1] == 0) return false;
        if(v[1] == 1) {
            if(v[2] == 0) return false;
            return v[0] % 2 == 0;
        }
        v[1] -= 2;
        int mn = min(v[1], v[2]);
        v[1] -= mn;
        v[2] -= mn;
        // cout << v[0] << "-" << v[1] << " " << v[2] << endl;
        if(v[2]) {
            v[2]--;
            if(v[2] == 0) return false;
            return v[0] % 2 == 0;
            // int mn2 = min(v[2], v[0]);
            // // cout << mn2 << endl;
            // v[2] -= mn2;
            // v[0] -= mn2;
            // // cout << v[0] << " " << v[1] << " " << v[2] << endl;
            // if(v[0] == 0 && v[1] == 0 && v[2] == 0) return false;
            // if(v[0]) {
            //     return false;
            // }
            // if(v[2]) {
            //     return true;
            // }
        }
        v[0] -= v[0] / 2 * 2;
        if(v[0] == 0 && v[1] == 0 && v[2] == 0) return false;
        if(v[0]) {
            v[0]--;
            if(v[0] == 0 && v[1] == 0 && v[2] == 0) return false;
            return true;
        }
        return false;
    }
    bool stoneGameIX(vector<int>& stones) {
        if(stones.size() == 1) return false;
        vector<int> v(3);
        for(auto x : stones) {
            v[x % 3]++;
        }
        bool a = fun1(v);
        swap(v[1], v[2]);
        bool b = fun1(v);
        cout << a << " " << b;
        return a || b;
    }
};