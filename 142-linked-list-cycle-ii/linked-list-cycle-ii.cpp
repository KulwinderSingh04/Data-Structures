/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head== nullptr) return NULL;
        ListNode* slow=head;
        ListNode* fast=head -> next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(fast==NULL || fast->next==NULL) return NULL;
        ListNode* temp=head;
        fast = fast -> next;
        while(temp!=fast) {
            temp = temp->next;
            fast = fast->next;
        }
        return temp;
    }
};