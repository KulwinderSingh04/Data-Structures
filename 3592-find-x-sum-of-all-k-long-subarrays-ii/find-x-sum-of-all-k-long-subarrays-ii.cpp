class Solution {
public:
    typedef pair<long long, long long> pp;
    long long sum = 0;
    set<pp> prim, sec;
    int x;
    void removeFromSet(pp p) {
        if(prim.find(p) != prim.end()) {
            sum -= p.first * p.second;
            prim.erase(p);
            if(sec.size()) {
                auto largest = *sec.rbegin();
                sec.erase(largest);
                prim.insert(largest);
                sum += 1LL * largest.first * largest.second;
            }
        } else if(sec.find(p) != sec.end()) {
            sec.erase(p);
        }
    }
    void insertInSet(pp p) {
        if(prim.size() < x || p > *prim.begin()) {
            prim.insert(p);
            sum += p.first * p.second;
            if(prim.size() > x) {
                auto smallest = *prim.begin();
                sum -= 1LL * smallest.first * smallest.second;
                prim.erase(smallest);
                sec.insert(smallest);
            }
        } else {
            sec.insert(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        unordered_map<long long, long long> mp;
        int i = 0;
        int j = 0;
        this -> x = x;
        while(j < n) {
            if(mp[nums[j]] > 0) {
                removeFromSet({mp[nums[j]], nums[j]});
            }
            mp[nums[j]]++;
            insertInSet({mp[nums[j]], nums[j]});

            if(j - i + 1 == k) {
                ans.push_back(sum);

                removeFromSet({mp[nums[i]], nums[i]});
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                } else {
                    insertInSet({mp[nums[i]], nums[i]});
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};