class CombinationIterator {
    vector<string> v;
    int pointer=0;
public:
    void solve(int i,string &characters,string &s,int &len)
    {
        if(s.size()==len)
        {
            v.push_back(s);
            return ;
        }
        if(s.size()>len||i==characters.size())
        return ;
        //choose 
        s.push_back(characters[i]);
        solve(i+1,characters,s,len);
        s.pop_back();
        //not choose
        solve(i+1,characters,s,len);
    }
    CombinationIterator(string characters, int combinationLength) {
        string s;
        solve(0,characters,s,combinationLength);
    }
    
    string next() {
        return v[pointer++];
    }
    
    bool hasNext() {
        return pointer<v.size();
    }
};