class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0,n=stones.size(),j,total;
        for(auto x:stones)sum+=x;
        total=sum;
        sum/=2;
        int dp[n+1][sum+1];
        //we need to find closest sum possible
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=0;
                else if(stones[i-1]>j)
                    dp[i][j]=dp[i-1][j]; 
                else
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-stones[i-1]];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        j=sum;
        
        while(j>=0&&!dp[n][j])j--;
        j*=2;
        // cout<<sum<<" "<<total<<" "<<j<<endl;
        return total-j;
    }
};