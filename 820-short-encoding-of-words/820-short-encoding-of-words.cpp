class trie{
    
   trie *child[26]={0};
    int wordcount=0;
    public:
    void insert(string &s)
    {
        if(this->child[s[0]-'a']==0)
        this->child[s[0]-'a']=new trie();
        trie *p=this->child[s[0]-'a'];
         p->wordcount++;
        for(int i=1;i<s.size();i++)
        {
            if(!p->child[s[i]-'a'])
                p->child[s[i]-'a']=new trie();
            p=p->child[s[i]-'a'];
            p->wordcount++;
        }
    }
    //count only if wordcount==0 because this means we dont have any merging suffix linke men,time  => if(me,time )<=this is mearging
    int count(string &s)
    {
        trie *p=this->child[s[0]-'a'];//this means we are jumping to first char
        for(int i=1;i<s.size();i++)
            p=p->child[s[i]-'a'];
         p->wordcount--;
        return p->wordcount==0?s.size()+1:0;
    }
};
class Solution {
    trie *first=0;
public:
    int minimumLengthEncoding(vector<string>& words) {
        first=new trie();
        for(int i=0;i<words.size();i++)
        {
            reverse(words[i].begin(),words[i].end());
            first->insert(words[i]);
        }
        int ans=0;
         for(int i=0;i<words.size();i++)
            ans+=first->count(words[i]);
        return ans;
    }
};