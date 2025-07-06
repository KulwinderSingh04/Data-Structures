class FindSumPairs {
public:
    vector<int> v1, v2;
    unordered_map<int, int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto x : nums2) m[x]++;
        v1 = nums1;
        v2 = nums2;
    }
    
    void add(int index, int val) {
        m[v2[index]]--;
        v2[index] += val;
        m[v2[index]]++;
    }
    
    int count(int tot) {
        int n = v1.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += m[tot - v1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */