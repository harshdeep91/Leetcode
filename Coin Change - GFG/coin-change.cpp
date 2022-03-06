// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) {
        long long int dp[2][n+1];
        bool flag=1;
        for(int i=0;i<=m;i++)
        {
            flag=!flag;
            for(int j=0;j<=n;j++)
            {
                
                if(j==0)
                dp[flag][j]=1;
                else if(i==0)
                dp[flag][j]=0;
                else if(S[i-1]<=j)
                dp[flag][j]=dp[flag][j-S[i-1]]+dp[!flag][j];
                else
                dp[flag][j]=dp[!flag][j];
                // cout<<dp[flag][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[flag][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends