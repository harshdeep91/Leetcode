// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=pow(10,9)+7;
    int nCr(int n, int r){
        // n-1Cr-1+n-1Cr=nCr;
        // cout<<n<<" "<<r<<endl;
        // if(r>n)
        // return 0;
        // if(n==r||n==0||r==0)
        // return 1;
        // return (nCr(n-1,r-1)+nCr(n-1,r)+mod)%mod;
        
        
          int dp[2][r+1];
        bool flag=1;
        for(int i=0;i<=n;i++)
        {
            flag=!flag;
            for(int j=0;j<=r;j++)
            {
                
                if(j==0||i==0||i==j)
                dp[flag][j]=1;
                else if(i>j)
                dp[flag][j]=(dp[!flag][j-1]+(dp[!flag][j]+mod)%mod)%mod;
                else
                dp[flag][j]=0;
                // cout<<dp[flag][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[flag][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends