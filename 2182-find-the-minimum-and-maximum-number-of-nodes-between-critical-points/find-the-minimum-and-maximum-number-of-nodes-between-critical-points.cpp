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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* c=head->next->next;
        int fidx=-1,sidx=-1,f=-1,s=-1;
        int idx=1;
        int mx,mn=INT_MAX;
        if(c==NULL) return {-1,-1};
        while(c)
        {
            if(b->val > a->val && b->val > c->val || b->val < a->val && b->val < c->val)
            {
                if(fidx==-1) fidx=idx;
                else sidx=idx;
                f=s;
                s=idx;
                if(f!=-1) mn=min(mn,s-f);
            }
            idx++;
            a=a->next;
            b=b->next;
            c=c->next;
        }
        if(fidx==-1 || sidx==-1) return {-1,-1};
        mx=sidx-fidx;
        return {mn,mx};
    }
};