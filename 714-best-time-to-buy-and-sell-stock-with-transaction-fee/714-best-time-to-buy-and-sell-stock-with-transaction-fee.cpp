class Solution {
    
public:
    // int solve(int i,int buy,int &fee,vector<int> &prices)
    // {
    //     //buy or not buy
    //     if(i==prices.size())return 0;
    //     if(dp[i][buy]!=-1)return dp[i][buy];
    //     if(buy)
    //     {
    //         return dp[i][buy]=max(-prices[i]+solve(i+1,0,fee,prices),solve(i+1,1,fee,prices));
    //     }
    //     else
    //     {
    //         return dp[i][buy]=max(prices[i]-fee+solve(i+1,1,fee,prices),solve(i+1,0,fee,prices));
    //     }
    // }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        //  int prevbuy=0,prevnotbuy=0,currbuy=0,currnotbuy=0;
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else
                dp[i][buy]=max(prices[i]-fee+dp[i+1][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};