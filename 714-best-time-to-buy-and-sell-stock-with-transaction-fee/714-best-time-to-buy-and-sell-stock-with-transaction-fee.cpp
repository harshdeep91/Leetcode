class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> prev(2,0),curr(2,0);
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                curr[buy]=max(-prices[i]+prev[0],prev[1]);
                else
                curr[buy]=max(prices[i]-fee+prev[1],prev[0]);
            }
            prev=curr;
        }
        return curr[1];
    }
};