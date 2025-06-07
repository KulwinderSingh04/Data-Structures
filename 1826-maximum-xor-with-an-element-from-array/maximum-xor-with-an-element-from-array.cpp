class Node {
    public:
    vector<Node*> links;
    Node() {
        links.resize(2, NULL);
    }
};

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1]; 
}
class Solution {
    Node* root;
public:
    void insert(int a) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (a >> i) & 1; 
            // cout << bit << " ";
            if(node -> links[bit] == NULL) {
                node -> links[bit] = new Node();
            }
            node = node -> links[bit];
        }
    }
    long long maxXor(int a) {
        Node* node = root;
        long long x = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (a >> i) & 1; 
            // cout << bit << " ";
            if(node -> links[!bit]) {
                x += 1 << i;
                node = node -> links[!bit];
            } else {
                node = node -> links[bit];
            }
        }
        return x;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root = new Node();
        sort(nums.begin(), nums.end());
        int j = 0;
        int n = nums.size();
        map<vector<int>, int> m;
        for(int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), cmp);
        vector<int> ans(queries.size(), -1);
        bool flag = false; 
        for(int i = 0; i < queries.size(); i++) {
            while(j < n && nums[j] <= queries[i][1]) {
                flag = true;
                insert(nums[j]);
                j++;
            }
            int idx = queries[i][2];
            if(flag) ans[idx] = maxXor(queries[i][0]); 
        }
        return ans;
    }
};