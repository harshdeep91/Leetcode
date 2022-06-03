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
//     bool check(int &m,vector<string>& strs)
//     {
       
//         for(int i=0;i<strs.size();i++)
//         {
//             for(int j=0,k=m-1;k<strs[0].size();j++,k++)
//             {
                
//             }
//         }
//         return 1;
//     }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),greater<string>());
        // int l=1,h=strs[0].size();
        // while(l<=h)
        // {
        //     int m=(l+h)>>1;
        //     if(check(m,strs))
        //         l=m+1;
        //     else
        //         h=m-1;
        // }
        // return h?h:-1;
        m.clear();
        for(int j=0;j<strs.size();j++)
        {
            solve(j,0,"",strs);
        }
        int mx=-1,t;
        for(auto x:m)
        {
            t=x.first.size();
            if(x.second==1)
                mx=max(mx,t);    
            // cout<<x.first<<" "<<x.second<<" "<<mx<<endl;    
        }
            
        return mx;
    }
};