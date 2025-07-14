/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s = "";
        ListNode* temp = head;
        while(temp) {
            s.push_back(temp -> val + 48);
            temp = temp -> next;
        }
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int num = s[i] - 48;
            ans += num * pow(2, n - 1 - i);
        }
        return ans;
    }
};