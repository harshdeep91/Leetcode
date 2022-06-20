class MagicDictionary {
    unordered_map<string,int> s;
public:
    MagicDictionary() {
        
    }
    //prefix and suffix
    void buildDict(vector<string> d) {
        for(int i=0;i<d.size();i++)
        {
            s[d[i]]++;
            for(int j=0;j<d[i].size();j++)
            {
                char c=d[i][j];
                d[i][j]='*';
                s[d[i]]++;
                d[i][j]=c;
            }
        }
    }
    
    bool search(string ss) {
        
        //hello jello 
        bool flag=0;
        if(s[ss]==1)
            flag=1;
        for(int j=0;j<ss.size();j++)
            {
                  char c=ss[j];
                   ss[j]='*';
                 if( (flag&&s[ss]>1)||(!flag&&s[ss]) )
                       return 1;
                   ss[j]=c;
            }
                   return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */