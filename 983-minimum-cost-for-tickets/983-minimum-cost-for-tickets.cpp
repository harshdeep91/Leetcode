class Solution {
    int mi=INT_MAX;
    int day[3]={0,6,29};
    vector<int> dp;
public:
    int solve(int i,vector<int>& days, vector<int>& costs)
    {
        
        if(i==days.size())
            return 0;
        if(dp[i]!=-1)return dp[i];
        // cout<<days[i]<<" "<<cost<<endl;
        //choose day 1
        int mi=INT_MAX,it;
        for(int j=0;j<3;j++)
        {
            it = upper_bound(days.begin(),days.end(),days[i]+day[j])-days.begin();
            mi=min(mi,solve(it,days,costs)+costs[j]);
        }
        return dp[i]=mi;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //choose day 1 ,day 7 , day 30
        //either we go day with cost 
        dp.resize(days.size(),-1);
        return solve(0,days,costs);
    }
};