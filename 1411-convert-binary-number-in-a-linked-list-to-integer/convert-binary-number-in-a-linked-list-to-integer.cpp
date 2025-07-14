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
    void fun(ListNode* head, int& i, int& ans) {
        if(head == NULL) return;
        fun(head -> next, i, ans);
        ans += head -> val * pow(2, i);
        i++;
    }
    int getDecimalValue(ListNode* head) {
        int i = 0, ans = 0;
        fun(head, i, ans);
        return ans;
    }
};