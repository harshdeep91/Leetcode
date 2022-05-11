class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5,1);
        int j=0;
        while(++j<=n)
        {
             for(int i=3;i>=0;i--)
            {
                if(j==1)
                dp[i]=5-i;
                else if(j==2)
                dp[i]=dp[i+1]+(5-i);
                else
                dp[i]+=dp[i+1];//2+1
            }

        }
        return dp[0];
    }
};