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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=NULL,*temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int k=count-n;
        temp=head;
        int pos=0;
        if(head==NULL)  return head;
        while(temp!=NULL){
            if(pos==k){
                if(p==NULL){
                    head=temp->next;
                }
                else{
                    p->next=temp->next;
                }
                delete temp;
                break;
            }
            p=temp;
            temp=temp->next;
            pos++;
        }
        return head;
    }
};