class Node{
    public:
    char data;
    Node *prev=0,*next=0;
    Node (char x)
    {
        data=x;
    }
        
};

class TextEditor {
     Node *first=0,*position=0,*last=0,*head=0;
public:
    TextEditor() {
            first=new Node('-');
            position=first;
            last=new Node('-');
            first->next=last;
            last->prev=first;
    }
    
    void addText(string text) {
        head=position->next;
        for(auto x:text)
        {
            position->next=new Node(x);
            position->next->prev=position;
            position=position->next;
        }
        head->prev=position;
        position->next=head;
    }
    
    int deleteText(int k) {
        int ans=0;
        Node *head=position->next;
        while(position!=first&&k--)
        {
            position=position->prev;
            ans++;
        }
        //linking again
           head->prev=position;
           position->next=head;
            return ans;
    }
    
    string cursorLeft(int k) {
        string ans;
        while(position!=first&&k--)
            position=position->prev;
        k=10;
        Node *p=position;
        while(p!=first&&k--)
        {
            ans.push_back(p->data);
            p=p->prev;
        }
       reverse(ans.begin(),ans.end());
            return ans;
    }
    
    string cursorRight(int k) {
      string ans;
        while(position->next!=last&&k--)
            position=position->next;
        k=10;
        Node *p=position;
        while(p!=first&&k--)
        {
            ans.push_back(p->data);
            p=p->prev;
        }
       reverse(ans.begin(),ans.end());
            return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */