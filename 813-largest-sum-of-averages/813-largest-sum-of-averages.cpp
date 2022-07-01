class Solution {
    vector<vector<double>> dp;
    public:
    double solve(int i,int k,vector<int> &nums)
    {
        
        if(k==0&&i==nums.size())return 0;
        if(k<=0||i==nums.size())return INT_MIN;
        // cout<<i<<" "<<k<<endl;
        double mx=0,sum=0;
        if(dp[i][k]!=-1)return dp[i][k];
        for(int j=i;j<nums.size();j++)
        {
            sum+=nums[j];
            mx=max(mx,sum/(j-i+1)+solve(j+1,k-1,nums));
        }
        // cout<<i<<" "<<k<<" "<<mx<<endl;
        return dp[i][k]=mx;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
       //chek notes
        dp.resize(nums.size()+1,vector<double>(k+1,-1));
        solve(0,k,nums);
        // for(int i=0;i<dp.size();i++)
        // {
        //     for(int j=0;j<=k;j++)
        //         cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        //     cout<<endl<<endl;
        // }
        return dp[0][k];
    }
};