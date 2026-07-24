class LRUCache {
public:
    class node{
    public:
        int key,value;
        node *next,*prev;
        node(int _key,int _value){
            key=_key;
            value=_value;
        }
    };
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node* newnode){
        node *temp=head->next;
        newnode ->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node *delnode){
        node *delprev=delnode->prev;
        node *delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key_) {
        if(mpp.find(key_)==mpp.end())   return -1;
        node *resnode=mpp[key_];
        deletenode(resnode);
        addnode(resnode);
        return resnode->value;
    }
    
    void put(int key_, int value) {
        if(mpp.find(key_)!=mpp.end()){
            node *existingnode=mpp[key_];
            existingnode->value=value;
            deletenode(existingnode);
            addnode(existingnode);
            return;
        }
        if(mpp.size()==cap){
            node*node=tail->prev;
            mpp.erase(node->key);
            deletenode(node);
            delete node;
        }
        node *newnode=new node(key_,value);
        addnode(newnode);
        mpp[key_]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */