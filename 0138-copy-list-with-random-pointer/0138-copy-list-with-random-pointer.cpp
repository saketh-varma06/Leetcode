/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insert_copy_in_between(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            Node *copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            temp=temp->next->next;
        }
    }
    void connect_random_pointers(Node *head){
        Node *temp=head;
        while(temp!=NULL){
            Node *copynode=temp->next;
            if(temp->random!=NULL)
                copynode->random=temp->random->next;
            temp=temp->next->next;
        }
    }
    Node *get_deep_copy(Node *head){
        Node *dummy=new Node(-1);
        Node *res=dummy;
        Node *temp=head;
        while(temp!=NULL){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        if(head==NULL)  return NULL;
        insert_copy_in_between(head);
        connect_random_pointers(head);
        return get_deep_copy(head);
    }
};