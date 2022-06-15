class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        //take only those word which have less value
        unordered_set<string> m;
        for(auto x:d)m.insert(x);
        int i=0 , up=0;
        string ans;
        while(i<s.size())
        {
             string t;
             up=0;
             while(i<s.size()&&s[i]!=' ')
             {
                 t.push_back(s[i++]);
                 if(m.find(t)!=m.end())
                     while(i<s.size()&&s[i]!=' ')i++;
             }
            if(i<s.size())
            t.push_back(s[i++]);
            ans+=t;
        }
        return ans;
    }
};