class Solution {
public:
    unordered_map<string,vector<char>> m;
    unordered_map<string,bool> dp;
    bool dfs(string t, int idx,string cur)
    {
        if(t.length()==1)
        {
            // cout<<t<<'\n';
            // cout<<cur<<'\n';
            return true;
        }
        
        if(idx==(t.length()-1))
        {
            return dfs(cur,0,"");
        }
        
        if(dp.find(t)!=dp.end())
            return dp[t];
        
        vector<char> v = m[t.substr(idx,2)];
        bool ans = false;
        for(int i=0;i<v.size();i++)
        {
            if(dfs(t,idx+1,cur+v[i]))
                return true;
        }
        
        
        dp[t] = ans;
        return ans;
    }
    
    bool pyramidTransition(string s, vector<string>& a) {
        dp.clear();
        m.clear();
        for(int i=0;i<a.size();i++)
        {
            m[a[i].substr(0,2)].push_back(a[i][2]);    
        }
        
        return dfs(s,0,"");
    }
};