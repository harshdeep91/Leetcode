void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}


struct Node{
  char data;
    Node *prev=0,*next=0;
};
class TextEditor {
     Node *first=0,*position=0,*last=0;
     int point=0;
public:
    TextEditor() {
           first=new Node;
           first->data='0';
            position=first;
            last=new Node;
            last->data='1';
            first->next=last;
        last->prev=first;
    }
    
    void addText(string text) {
        //postition->next 
        //insert return the head of string text
        Node *t=0,*head=0;
        int i=0;
        head=position->next;
        while(i<text.size())
        {
            t=new Node;
            t->data=text[i++];
            position->next=t;
            t->prev=position;
            position=t;
            point++;
        }
        head->prev=position;
        position->next=head;
        //connect the head
        cout<<point<<" ";
    }
    
    int deleteText(int k) {
        int ans=0;
        Node *head=position->next;
        while(position!=first&&k--)
        {
            position=position->prev;
            ans++;
            point--;
        }
           position->next=head;
            head->prev=position;
        cout<<point<<" ";
            return ans;
            
    }
    
    string cursorLeft(int k) {
        string ans;
        int i=k;
        while(position!=first&&i--)
        {
            position=position->prev;
            point--;
        }
        //now return ans from position to last min len
        i=0;
        Node *p=position;
        while(p!=first&&i<10)
        {
            ans.push_back(p->data);
            i++;
            p=p->prev;
        }
       reverseStr(ans);
        cout<<point<<" ";
            return ans;
    }
    
    string cursorRight(int k) {
      string ans;
        int i=k;
        while(position->next!=last&&i--)
        {
            position=position->next;
            point++;
        }
        //now return ans from position to last min len
        i=0;
        Node *p=position;
        while(p!=first&&i<10)
        {
            ans.push_back(p->data);
            i++;
            p=p->prev;
        }
       reverseStr(ans);
        cout<<point<<" ";
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