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
    ListNode *reverse(ListNode *temp){
        ListNode *prev=NULL;
        while(temp!=NULL){  
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode *getkthnode(ListNode *temp,int k){
        k--;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *prevNode=NULL;
        while(temp!=NULL){
            ListNode *kthnode=getkthnode(temp,k);
            if(kthnode==NULL){
                if(prevNode)    prevNode->next=temp;
                break;
            }
            ListNode *nextnode=kthnode->next;
            kthnode->next=NULL;
            reverse(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevNode->next=kthnode;
            }
            prevNode=temp;
            temp=nextnode;
        }
        return head;
    }
};