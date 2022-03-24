// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
public:

long long dp[10][1005];
int matrix[4][3] = {
{1,2,3},
{4,5,6},
{7,8,9},
{-1,0,-1}
};

long long solve(int i, int j, int n)
{
if(n == 1) return 1;
int v = matrix[i][j];
if(dp[v][n] != -1) return dp[v][n];

long long a = solve(i, j, n-1); // take number itself
long long b, c, d, e;
b = c = d = e = 0;

if(j >= 1 && matrix[i][j-1] != -1) b = solve(i, j-1, n-1); // left movement possible
if(j < 2 && matrix[i][j+1] != -1) c = solve(i, j+1, n-1); // right movement possible
if(i >= 1 && matrix[i-1][j] != -1) d = solve(i-1, j, n-1); // down movement possible
if(i < 3 && matrix[i+1][j] != -1) e = solve(i+1, j, n-1); // up movement possible

return dp[v][n] = a+b+c+d+e;
}

long long getCount(int N)
{
dp[10][N+1];
memset(dp, -1, sizeof(dp));

long long ans = 0;
for(int i = 0; i < 4; i++)
for(int j = 0; j < 3; j++)
if(matrix[i][j] != -1) // not * and #
ans += solve(i, j, N);

return ans;
}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends