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
    ListNode *findnthnode(ListNode *temp,int k){
        int cnt=1;
        while(temp!=NULL){
            if(cnt==k)  return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)  return head;
        int n=1;
        ListNode *tail=head;
        while(tail->next!=NULL){
            n++;
            tail=tail->next;
        }
        if(k%n==0)  return head;
        k%=n;
        tail->next=head;
        ListNode * newlastnode=findnthnode(head,n-k);
        head=newlastnode->next;
        newlastnode->next=NULL;
        return head;
    }
};