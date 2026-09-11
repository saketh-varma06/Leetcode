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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL && temp->next!=NULL){
            ListNode*first=temp;
            ListNode*second=temp->next;
            ListNode *third=second->next;
            if(prev)    prev->next=second;
            else        head=second;
            second->next=first;
            first->next=third;
            prev=first;
            temp=third;
        }
        return head;
    }
};