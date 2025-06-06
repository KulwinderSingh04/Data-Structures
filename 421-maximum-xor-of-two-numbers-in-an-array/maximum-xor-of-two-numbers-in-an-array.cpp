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
    void insert(string a) {
        Node* node = root;
        for(int i = 0; i < 32; i++) {
            if(node -> links[a[i] - 48] == NULL) {
                node -> links[a[i] - 48] = new Node();
            }
            node = node -> links[a[i] - 48];
        }
    }
    long long maxXor(string a) {
        Node* node = root;
        long long x = 0;
        for(int i = 0; i < 32; i++) {
            if(node -> links[!(a[i] - 48)]) {
                x += pow(2, 31 - i);
                node = node -> links[!(a[i] - 48)];
            } else {
                node = node -> links[a[i] - 48];
            }
        }
        return x;
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            string a(32, '0');
            int num = nums[i];
            int j = 0;
            while(num) {
                a[j++] = (num % 2 + 48);
                num /= 2;
            }
            reverse(a.begin(), a.end());
            insert(a);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            
            string a(32, '0');
            int num = nums[i];
            int j = 0;
            while(num) {
                a[j++] = (num % 2 + 48);
                num /= 2;
            }
            reverse(a.begin(), a.end());
            ans = max(ans, maxXor(a));
        }
        return ans;
    }
};