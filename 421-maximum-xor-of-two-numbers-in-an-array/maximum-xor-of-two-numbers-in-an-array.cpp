class Node {
    public:
    vector<Node*> links;
    Node() {
        links.resize(2, NULL);
    }
};
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
            if(node -> links[!bit]) {
                x += 1 << i;
                node = node -> links[!bit];
            } else {
                node = node -> links[bit];
            }
        }
        return x;
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            insert(nums[i]);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, maxXor(nums[i]));
        }
        return ans;
    }
};