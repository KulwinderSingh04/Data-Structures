class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int a = maxWeight / w;
        if(a < (n * n)) return a;
        return n * n;
    }
};