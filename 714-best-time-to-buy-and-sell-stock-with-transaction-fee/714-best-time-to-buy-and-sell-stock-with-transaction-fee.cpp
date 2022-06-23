class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> prev(2,0),curr(2,0);
        int currbuy=0,currnotbuy=0,prevbuy=0,prevnotbuy=0;
        for(int i=prices.size()-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy)
                currbuy=max(-prices[i]+prevnotbuy,prevbuy);
                else
                currnotbuy=max(prices[i]-fee+prevbuy,prevnotbuy);
            }
            prevbuy=currbuy;
            prevnotbuy=currnotbuy;
        }
        return currbuy;
    }
};