class Solution {
    vector<int> ans;
    int t;
public:
    void solve(int k)
    {
        // cout<<k<<" ";
            for(int i=0;i<=9&&k+i<=t;i++)
            {
                ans.push_back(k+i);
                if((k+i)*10<=t)
                  solve((k+i)*10);
            }
    }
    vector<int> lexicalOrder(int n) {
        ans.clear();
        t=n;
        for(int i=1;i<=9&&i<=t;i++)
        {
            ans.push_back(i);
            if(i*10<=t)
            solve(i*10);
        }
        return ans; 
    }
};