class Fancy {
public:
    typedef pair<long long, long long> pp;
    long long add;
    long long mul;
    vector<long long> v;
    long long M = 1e9 + 7;
    long long power(long long a, long long b) {
        if(b == 0) return 1;
        long long half= power(a, b / 2) % M;
        if(b % 2) return (half * half) % M * a % M;
        return (half * half) % M;
    }
    Fancy() {
        add = 0;
        mul = 1;
    }
    
    void append(int val) {
        v.push_back((val - add % M + M) % M * power(mul, M - 2));
    }
    
    void addAll(int inc) {
        add += inc;
        add %= M;
    }
    
    void multAll(int m) {
        add *= m;
        add %= M;
        mul *= m;
        mul %= M;
    }
    
    int getIndex(int idx) {
        if(idx >= v.size()) return -1;
        return (v[idx] % M * mul % M + add) % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */