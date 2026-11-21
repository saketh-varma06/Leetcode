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
    ListNode * reverse_LL(ListNode *head){
        ListNode * prev=NULL,*temp=head;
        while(temp!=NULL){
            ListNode*curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        while(head==NULL || head->next==NULL){
            return;
        }
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode * second=reverse_LL(slow->next);
        slow->next=NULL;
        ListNode *first=head;
        while(second!=NULL){
            ListNode * temp= first->next;
            first->next=second;
            first=second;
            second=second->next;
            first->next=temp;
            first=temp;
        }
    }
};