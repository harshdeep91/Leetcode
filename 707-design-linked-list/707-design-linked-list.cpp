struct Node{
    int val;
    Node *next;
};
class MyLinkedList {
    Node *head=0,*last=0,*p,*q,*r;
    int size=0;
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(index>=size)
            return -1;
         p=head;
        for(int i=0;i<index;i++)
           p=p->next;
         return p->val;     
    }
    
    void addAtHead(int val) {
        p=new Node();
        p->val=val;
        if(!head)
        {
            head=p;
            last=p;
            p->next=0;
        }
        else
            p->next=head,head=p;
        size++;
    }
    
    void addAtTail(int val) {
        p=new Node();
        p->val=val;
        if(!head)
        {
            head=p;
            last=p;
            p->next=0;
        }
        else
            last->next=p,last=p;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0||index>=size)
        {
            if(index==0) addAtHead(val);
            else if(index==size)addAtTail(val);
            return;
        }
        p=head;
        for(int i=0;i<index-1;i++)
            p=p->next;
        q=new Node();
        q->val=val;
        q->next=p->next;
        p->next=q;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size)return;
        p=head,q=0;
        for(int i=0;i<index;i++)
            q=p,p=p->next;
        
            if(q)
            q->next=p->next;
            else head=p->next;
            
            if(!p->next)//last
                last=q;
            delete p;   
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */