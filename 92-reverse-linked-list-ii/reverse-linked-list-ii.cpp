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
    ListNode* reverse(ListNode* head)
    {
        ListNode* p=NULL;
        ListNode* curr=head;
        ListNode* n=curr;
        while(curr)
        {
            n=curr->next; 
            curr->next=p;
            p=curr;
            curr=n;
        }
        return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if(left==right) return head;
        ListNode* temp=head;
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        ListNode* d=NULL;
        int count=1;
        while(temp)
        {
            if(count==left-1) a=temp;
            if(count==left) b=temp;
            if(count==right) c=temp;
            if(count==right+1) d=temp;
            count++;
            temp=temp->next;
        }
        if(a!=NULL) a->next=NULL;
        c->next=NULL;
        c=reverse(b);
        if(a!=NULL) a->next=c;
        b->next=d;
        if(a) return head;
        return c;
    }
};