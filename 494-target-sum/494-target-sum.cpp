class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        int sum=0,count=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        sum=(target+sum);
        if(sum<0||sum&1)
            return 0;
        sum/=2;
        
        sort(nums.begin(),nums.end(),greater<int>());
        while(!nums.empty()&&nums.back()==0)
        {
            nums.pop_back();
            count++;
        }
        n=nums.size();
        int dp[n+1][sum+1];
        //the case of 0 must be checked first
        //we can count zero
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=0;   
                else if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else 
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];    
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;

        }
        if(count)
            return dp[n][sum]*pow(2,count);
        return dp[n][sum];
    }
};