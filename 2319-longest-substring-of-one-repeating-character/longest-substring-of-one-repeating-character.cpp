class Node {
    public:
    int pre;
    int suf;
    int mx;
    char prech, sufch;
    Node() {
        pre = suf = mx = 0;
    }
};
class Solution {
public:
    void buildTree(int i, int l, int r, string& s, vector<Node>& segTree) {
        if(l > r) return;
        if(l == r) {
            segTree[i].pre = segTree[i].suf = segTree[i].mx = 1;
            segTree[i].prech = segTree[i].sufch = s[l];
            return;
        }
        int mid = l + (r - l) / 2;
        buildTree(2 * i + 1, l, mid, s, segTree);
        buildTree(2 * i + 2, mid + 1, r, s, segTree);
        segTree[i].sufch = segTree[2 * i + 2].sufch;
        if(segTree[2* i + 2].mx == r - mid && segTree[2 * i + 1].sufch == segTree[2 * i + 2].prech) {
            segTree[i].suf = segTree[2 * i + 2].suf + segTree[2 * i + 1].suf;
        } else {
            segTree[i].suf = segTree[2 * i + 2].suf;
        }
        segTree[i].prech = segTree[2 * i + 1].prech;
        if(segTree[2* i + 1].mx == mid - l + 1 && segTree[2 * i + 1].sufch == segTree[2 * i + 2].prech) {
            segTree[i].pre = segTree[2 * i + 2].pre + segTree[2 * i + 1].pre;
        } else {
            segTree[i].pre = segTree[2 * i + 1].pre;
        }
        segTree[i].mx = max(segTree[2 * i + 1].mx, segTree[2 * i + 2].mx);
        if(segTree[2 * i + 1].sufch == segTree[2 * i + 2].prech) {
            segTree[i].mx = max(segTree[i].mx, segTree[2 * i + 2].pre + segTree[2 * i + 1].suf);
        }
    }
    void update(int i, int l, int r, int idx, char ch, vector<Node>& segTree) {
        if(l > r) return;
        if(l == r) {
            segTree[i].prech = segTree[i].sufch = ch;
            segTree[i].pre = segTree[i].suf = segTree[i].mx = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) update(2 * i + 1, l, mid, idx, ch, segTree);
        else update(2 * i + 2, mid + 1, r, idx, ch, segTree);
        segTree[i].sufch = segTree[2 * i + 2].sufch;
        if(segTree[2* i + 2].mx == r - mid && segTree[2 * i + 1].sufch == segTree[2 * i + 2].prech) {
            segTree[i].suf = segTree[2 * i + 2].suf + segTree[2 * i + 1].suf;
        } else {
            segTree[i].suf = segTree[2 * i + 2].suf;
        }
        segTree[i].prech = segTree[2 * i + 1].prech;
        if(segTree[2* i + 1].mx == mid - l + 1 && segTree[2 * i + 1].sufch == segTree[2 * i + 2].prech) {
            segTree[i].pre = segTree[2 * i + 2].pre + segTree[2 * i + 1].pre;
        } else {
            segTree[i].prech = segTree[2 * i + 1].prech;
            segTree[i].pre = segTree[2 * i + 1].pre;
        }
        segTree[i].mx = max(segTree[2 * i + 1].mx, segTree[2 * i + 2].mx);
        if(segTree[2 * i + 1].sufch == segTree[2 * i + 2].prech) {
            segTree[i].mx = max(segTree[i].mx, segTree[2 * i + 2].pre + segTree[2 * i + 1].suf);
        }
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        vector<Node> segTree(4 * n);
        buildTree(0, 0, n - 1, s, segTree);
        vector<int> ans;
        for(int q = 0; q < queryIndices.size(); q++) {
            update(0, 0, n - 1, queryIndices[q], queryCharacters[q], segTree);
            ans.push_back(segTree[0].mx);
        }
        return ans;
    }
};