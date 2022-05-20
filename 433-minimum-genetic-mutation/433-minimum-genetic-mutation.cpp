class Solution {
    char a[4]={'A','C','G','T'};
public:
    int solve(string start,string end,unordered_set<string> &m)
    {
        if(start==end)
            return 0;
        int mi=9,tmp;
        // cout<<endl;
        for(int i=0;i<8;i++)
        {
            tmp=start[i];
                for(int j=0;j<4;j++)
                {
                    if(tmp==a[j])continue;
                    start[i]=a[j];
                    // cout<<start<<" ";
                    if(m.find(start)!=m.end())//we found it
                    {
                        m.erase(start);
                        mi=min(mi,solve(start,end,m)+1);
                        m.insert(start);
                    }
                }
            start[i]=tmp;
        }
        return mi;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s;
        for(auto x:bank)
            s.insert(x);
        int ans=solve(start,end,s);
        return ans==9?-1:ans;
    }
};