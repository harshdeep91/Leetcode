// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int price[]) {
        int profit[k + 1][n + 1];
 
    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;
 
    // profit is 0 if we don't do any transaction
    // (i.e. k =0)
    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;
 
    // fill the table in bottom-up fashion
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            int max_so_far = price[j] - price[0];
 
            for (int m = 1; m < j; m++)
                    max_so_far = max(max_so_far,
                                 price[j] - price[m] + profit[i - 1][m-1]);
            profit[i][j] = max(profit[i][j - 1], max_so_far);
        }
    }
    // for(int i=0;i<=k;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //     cout<<profit[i][j]<<" ";
    //     cout<<endl;
    // }
    return profit[k][n - 1];
    }
// 0 0 0 0 0 0 0 
// 0 0 0 70 70 75 0 
// 0 0 0 70 70 85 0 

                        // 0 0 0 0 0 0 0 
                        // 0 12 12 70 70 75 0 
                        // 0 12 12 82 82 87 0 
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends