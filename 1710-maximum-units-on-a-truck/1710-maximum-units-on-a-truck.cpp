class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int t) {
       //this is not a knapsack because each box has no that can be breakable
        sort(b.begin(),b.end(),cmp);
        // for(auto x:b)
        //     cout<<x[0]<<" "<<x[1]<<endl;
        int ans=0,i=0;
        while(t--&&i<b.size())
        {
            if(b[i][0]>0)
            {
                ans+=b[i][1];
                b[i][0]--;
            }
            else
                i++,t++;
        }
        return ans;
    }
};