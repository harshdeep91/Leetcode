class Solution {
     unordered_map<string,int> m;
public:
    void solve(int i,int j,string s,vector<string>& strs)
    {
        if(j==strs[i].size())
        {
            m[s]++;
             return;
        }
        //include
        solve(i,j+1,s+strs[i][j],strs);
        //exclude
        solve(i,j+1,s,strs);
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),greater<string>());
        m.clear();
        for(int j=0;j<strs.size();j++)
            solve(j,0,"",strs);
        int mx=-1,t;
        for(auto x:m)
        {
            t=x.first.size();
            if(x.second==1)
                mx=max(mx,t);       
        }
            
        return mx;
    }
};