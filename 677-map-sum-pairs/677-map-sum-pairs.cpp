class trie{
    trie * child[26]={0};
    int sum=0;
    public:
    void insert(string &s,int &key)
    {
        //if duplicate simply subtract and add 
        trie *p=this;
        for(int i=0;i<s.size();i++)
        {
            if(!p->child[s[i]-'a'])
                p->child[s[i]-'a']=new trie();
            p= p->child[s[i]-'a'];
              p->sum+= key;
        }
    }
    int count(string &s)
    {
        trie *p=this;
        for(int i=0;i<s.size();i++)
        {
            if(!p->child[s[i]-'a'])return 0;
             p=p->child[s[i]-'a'];
        }
        return p->sum;
    }
};

class MapSum {
    unordered_map<string,int> m;
    trie first;
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int t=val;
        if(m.find(key)!=m.end())
            t-=m[key];
         m[key]=val;
        first.insert(key,t);
    }
    
    int sum(string prefix) {
        return first.count(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */