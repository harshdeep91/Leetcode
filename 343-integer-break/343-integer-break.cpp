class Solution {
public:
    void solve(int j,int product,int n,int &mx,int k)
    {
        if(n==0&&k>1)
        {
            mx=max(product,mx);
            return ;
        }
        if(n<0)
            return;
        while(j<=n)
        {
            solve(j,product*j,n-j,mx,k+1);
            j++;
        }
    }
    int integerBreak(int n){
        int mx=0,val=n;
        solve(1,1,n,mx,0);
        return mx;
    }
};