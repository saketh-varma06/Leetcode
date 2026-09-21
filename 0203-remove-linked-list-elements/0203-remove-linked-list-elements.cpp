/**
 * Definition for singly-linked list.
uct ListNode {
 *     int val;
 *     ListNode *next;
 *    * str  ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)  return head;
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        if(head==NULL)  return head;
        ListNode * temp=head;
        ListNode * prev=NULL;
        while(temp!=NULL){
            if(temp->val==val){
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};