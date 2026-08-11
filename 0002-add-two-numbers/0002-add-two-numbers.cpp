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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode * ans =new ListNode(0);
        ListNode* r=ans;
        while(temp1!=nullptr || temp2!=nullptr){
            int x=(temp1!=nullptr) ? temp1->val : 0;
            int y=(temp2!=nullptr) ? temp2->val : 0;
            int sum=x+y+carry;
            carry=sum/10;
            r->next=new ListNode(sum%10);
            r=r->next;
            if(temp1!=nullptr)      temp1=temp1->next;
            if(temp2!=nullptr)      temp2=temp2->next;
        }
        if(carry>0)     r->next=new ListNode(carry);
        return ans->next;
    }
};