class Solution {
    vector<int> ans;
public:
    void solve(int k,int n)
    {
        // cout<<k<<" ";
        if(k<=n)
        {
            for(int i=0;i<=9&&k+i<=n;i++)
            {
                ans.push_back(k+i);
                  solve((k+i)*10,n);
            }
        }
            
    }
    vector<int> lexicalOrder(int n) {
        ans.clear();
        for(int i=1;i<=9&&i<=n;i++)
        {
            ans.push_back(i);
            solve(i*10,n);
        }
        return ans; 
    }
};