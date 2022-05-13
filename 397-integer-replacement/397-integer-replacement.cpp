class Solution {
    map<unsigned,int> dp;
public:
    int solve(unsigned n)
    {
        // cout << n<<" ";
        if(n==1)
            return 0;
            if(dp[n])
                return dp[n];
        if(n&1)
            return dp[n]=min(solve(n + 1),solve (n - 1))+1;
        else
        return dp[n]= solve(n / 2) + 1;
    }
    int integerReplacement(int n) {
        return solve(n);
    }
};