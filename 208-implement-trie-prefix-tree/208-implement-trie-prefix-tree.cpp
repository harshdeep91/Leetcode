struct Node{
    char val;
    Node* child[256]={0};
    int wordcount=0;
    int prefix=0;  
};
class Trie {
  Node *root;
public:
    Trie() {
        root=new Node;
    }
    
    void insert(string s) {
        Node *p=root;
        for(int i=0;i<s.size();i++)
        {
            if(!p->child[s[i]])
            {
                p->child[s[i]]=new Node;
                p->child[s[i]]->val=s[i];
            }
            p=p->child[s[i]];
            p->prefix++;
        }
        p->wordcount++;
    }
    
    bool search(string s) {
        Node *p=root;
        for(int i=0;i<s.size();i++)
        {
            if(!p->child[s[i]])
                return 0;
            p=p->child[s[i]];
        }
        return p->wordcount;
    }
    
    bool startsWith(string s) {
        Node *p=root;
        for(int i=0;i<s.size();i++)
        {
            if(!p->child[s[i]])
                return 0;
            p=p->child[s[i]];
        }
        return p->prefix;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */