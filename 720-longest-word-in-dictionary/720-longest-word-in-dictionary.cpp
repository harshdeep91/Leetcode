class trie{
    
    public:
    trie * child[26]={0};
    int wordcount=0;
    char t='\0';
    bool end=0;
    void insert(string s)
    {
        // cout<<s<<"--> ";
        trie *p=this;
        for(auto x:s)
        {
            if(!p->child[x-'a'])
            {
                p->child[x-'a']=new trie;
                p->child[x-'a']->t=x;
            }
            p=p->child[x-'a'];
            p->wordcount++;
            // cout<<p->t<<" "<<p->wordcount<<endl;
        }
        p->end=1;
    }
    string count(trie *p)
    {
        // cout<<p->t<<"-->";
        string s,len;
        int mx=0;
        if(!p->end)return "";
        for(int i=0;i<26;i++)
        {
            // if(p->child[i])
               
            if(p->child[i]&&p->child[i]->wordcount<p->wordcount)
            {
                 // cout<<p->child[i]->t<<" "<<p->child[i]->wordcount<<endl;
                len=count(p->child[i]);
                if(len.size()>mx)
                {
                    mx=len.size();
                    s=len;
                }
            }
        }
        s.push_back(p->t);
        // cout<<s<<endl;
        return s;
    }
};
class Solution {
    
public:
    string longestWord(vector<string>& words) {
        // sort(words.begin(),words.end());
    trie *first=new trie();    
        for(auto x:words)
        {
            first->insert(x);
            // cout<<x<<" ";
        }
        // cout<<endl;
//         
        string s,len;
        int mx=0;
        for(int i=0;i<26;i++)
        {
            if(first->child[i])
            {
                len=first->count(first->child[i]);
                if(len.size()>mx)
                {
                    mx=len.size();
                    s=len;
                }
            }
        }
        // cout<<s<<" "<<len<<endl;
        reverse(s.begin(),s.end());
        return s;
    }
};