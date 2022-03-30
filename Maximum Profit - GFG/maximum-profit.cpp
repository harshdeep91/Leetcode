// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
vector<vector<vector<int>>> dp; //3D DP memoization
int N;
    int solve(int prices[], int i, int x, int k){
        if(i>=N or k==0) return 0; //Base Case
        if(dp[i][k][x]!=-1) return dp[i][k][x];
        int profit=0;
        if(x==0){
            int Buy= solve(prices, i+1, 1, k)-prices[i]; //if we buy a stock then we recurse on rest of the array, subtract prices[i] from the current profit and change state to x=1 (selling)
            int noBuy= solve(prices, i+1, 0, k); //if we do not buy a stock then we simply recurse on the rest of the array and the state remains the same x=0 (buying)
            profit=max(Buy, noBuy);
        }
        else if(x==1){
            int Sell= solve(prices, i+1, 0, k-1)+prices[i]; //if we sell a stock then we recurse on rest of the array and add prices[i] to the current profit, state changes to x=0 (Buying) and k decreseas by 1 since a transaction is complete
            int noSell= solve(prices, i+1, 1, k); //if we do not sell a stock then we recurse on rest of the array, state remains the same (=1 for selling)
            profit=max(Sell, noSell);
        }
        return dp[i][k][x]= profit;
    }
    
    int maxProfit(int k, int n, int A[]) {
         
          dp= vector<vector<vector<int>>>(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
          N=n;
        return solve(A, 0, 0, k); //we start from i=0 and x=0 since we've to buy a stock initially
    }
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