class Solution {
    vector<vector<int>> dp;
public:
    int solve(int i,int buy,int &fee,vector<int> &prices)
    {
        //buy or not buy
        if(i==prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy)
        {
            return dp[i][buy]=max(-prices[i]+solve(i+1,0,fee,prices),solve(i+1,1,fee,prices));
        }
        else
        {
            return dp[i][buy]=max(prices[i]-fee+solve(i+1,1,fee,prices),solve(i+1,0,fee,prices));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        //  int prevbuy=0,prevnotbuy=0,currbuy=0,currnotbuy=0;
        // for(int i=prices.size()-1;i>=0;i--)
        // {
        //     for(int buy=0;buy<=1;buy++)
        //     {
        //         int profit=0;
        //         if(buy==1)//means we need to buy here by either not buying or if buying
        //         {
        //             profit+=max(-prices[i]+prevnotbuy,prevnotbuy);
        //         }
        //         else
        //         {
        //             profit+= max(prices[i]-fee+prevbuy,prevbuy);
        //         }
        //         currbuy=prevbuy
        //     }
        // }
        return solve(0,1,fee,prices);
    }
};