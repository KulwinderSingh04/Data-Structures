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
    class cmp {
        public:
        bool operator()(ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i = 0; i < n; i++) {
            if(lists[i]) pq.push(lists[i]);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            temp -> next = t;
            temp = temp -> next;
            if(t -> next) pq.push(t -> next);
        }
        return dummy -> next;
    }
};