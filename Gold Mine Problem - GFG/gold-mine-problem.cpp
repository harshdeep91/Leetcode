// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        long long dp[n][m],sum=0,mod=pow(10,9)+7;
        for(int j=m-1;j>=0;j--)//col
        {
            for(int i=0;i<n;i++)//row
            {
                dp[i][j]=M[i][j];
                if(j<m-1)
                {
                    int x=i+1<n&&j+1<m?dp[i+1][j+1]:0;//diag down
                    int y=i-1>=0&&j+1<m?dp[i-1][j+1]:0;//diag up
                    int z=j+1<m?dp[i][j+1]:0;//right
                    dp[i][j]=(((dp[i][j]+mod)%mod+(max(z,max(x,y))+mod)%mod))%mod;
                }
                sum=max(sum,dp[i][j]);
            }
        }
        // long long int x=INT_MAX;
        // x=(x+mod)%mod;
        // cout<<x;
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends