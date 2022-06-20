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
                s[d[i].substr(0,j)+"*"+d[i].substr(j+1)]++;
            }
        }
    }
    
    bool search(string ss) {
        
        //hello jello 
        bool flag=0;
        if(s[ss]==1)
            flag=1;
        string t;
        for(int j=0;j<ss.size();j++)
            {
                  t=ss.substr(0,j)+"*"+ss.substr(j+1);
                 if( (flag&&s[t]>1)||(!flag&&s[t]) )
                       return 1;
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