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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)     return head;
        int cnt=0;
        ListNode* temp=head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            cnt++;
            if(cnt==left){
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        ListNode* first=temp;
        ListNode *revprev=NULL;
        while(cnt<=right){
            ListNode* front=temp->next;
            temp->next=revprev;
            revprev=temp;
            temp=front;
            cnt++;
        }
        if(prev!=NULL){
            prev->next=revprev;
        }
        else    head=revprev;
        first->next=temp;
        return head;
    }
};