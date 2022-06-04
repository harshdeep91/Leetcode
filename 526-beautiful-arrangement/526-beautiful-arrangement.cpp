class Solution {
    int count=0;
public:
    void dfs(int i,vector<bool> &vis, vector<int> a[],int n)
    {
        // cout<<i<<" ";
        if(i>n)
        {
            count++;
            return;
        }
        for(auto x:a[i])
            if(!vis[x])
            {
                // cout<<x<<endl;
                vis[x]=1;
                dfs(i+1,vis,a,n);
                vis[x]=0;
            }
        // vis[i]=0;
    }
    int countArrangement(int n) {
        int ans=1,i=1;
        count=0;
        vector<int> a[n+1];
        vector<bool> vis(n+1,0);
         while(i<=n)
         {
             for(int j=1;j<=n;j++)
                 if(i%j==0||j%i==0)
                     a[i].push_back(j);
             i++;
         }
        // for(int j=1;j<=n;j++)
        // {
        //     cout<<j<<"---> ";
        //     for(auto x:a[j])
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        dfs(1,vis,a,n);
        return count;
    }
};