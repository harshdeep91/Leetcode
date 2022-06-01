class Solution {
public:
    int solve(int i,int j,vector<int> &nums)//[i,j] Not (i,j)
    {
        // cout<<one<<" "<<i<<" "<<j<<" "<<endl;
        if(i>j)//array ends
        {
            
            // cout<<"REturning\n";
            return 0;
            // nums[i];
        }
        
    
        // choose first or last
        //one=> player 1 turn
        // if(one)                //this should return one turne
        int x=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int y=nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));
         // cout<<one<<" "<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<z<<endl;
        
        return max(x,y);
        // else
        //     return min(nums[i]+solve(1,i+1,j,nums),nums[j]+solve(1,i,j-1,nums));
    }
    bool PredictTheWinner(vector<int>& nums) {
      
        int n=nums.size();
        int dp[n][n],sum=0;
        for(int g=0;g<n;g++)
        {
            for(int j=g,i=0;j<n;j++,i++)
            {
                if(g==0)
                    dp[i][j]=nums[i];
                else if(g==1)
                    dp[i][j]=max(nums[j],nums[i]);
                else
                 dp[i][j]=max(nums[i]+min(dp[i+2][j],dp[i+1][j-1]),nums[j]+min(dp[i][j-2],dp[i+1][j-1]));
            }
            sum+=nums[g];
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return 2*dp[0][n-1]>=sum;
    }
};

//error i have done => return made bool 
//for player to win it must choose the maxsum =>
// for that A first choose any number then b will choose maxsum => for that A must choose min number