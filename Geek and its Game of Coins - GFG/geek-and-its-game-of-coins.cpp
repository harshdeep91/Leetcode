// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findWinner(int N, int X, int Y)
	{
            	vector<bool> dp(N+1,false);
             for(int i=0;i<=N;i++){
                 if(dp[i]==false){
                     if(i+1<=N) dp[i+1]=true;
                     if(i+X<=N) dp[i+X]=true;
                     if(i+Y<=N) dp[i+Y]=true;
                 }
             }
             return dp[N];
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends