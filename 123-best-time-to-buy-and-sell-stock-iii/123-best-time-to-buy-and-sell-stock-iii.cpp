class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),dp[n],mi=0,mx=0;
        dp[0]=0;
        // cout<<dp[0]<<" ";
        for(int i=1;i<n;i++)
        {
            dp[i]=prices[i]-prices[mi];
            dp[i]=max(dp[i],dp[i-1]);
            if(prices[i]<=prices[mi])
                mi=i;
            // mx=max(dp[i],mx);
            // cout<<dp[i]<<" ";
        }
        // cout<<endl;
        mi=n-1;
        int dp2[n];
        dp2[n-1]=0;
        // cout<<dp2[n-1]<<" ";/
        for(int i=n-2;i>=0;i--)
        {
            dp2[i]=prices[mi]-prices[i];
            //exclude
            dp2[i]=max(dp2[i],dp2[i+1]);
            if(prices[i]>=prices[mi])
                mi=i;
            // mx=max(dp[i],mx);
            
        }
        for(int i=0;i<n-1;i++)
        {
             // cout<<dp2[i]<<" ";
            mx=max(mx,max(dp[i],dp[i]+dp2[i+1]));
        }
        mx=max(mx,dp[n-1]);
        // cout<<dp2[n-1]<<" ";
        return mx;
        
    }
};