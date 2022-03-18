// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        int dp[A.size()+1][B.size()+1];
        for(int i=0;i<=A.size();i++)
        {
            for(int j=0;j<=B.size();j++)
            {
                if(i==0&&j==0)
                dp[i][j]=1;
                else if(i==0)
                dp[i][j]=B[j-1]==C[j-1]&&dp[i][j-1];
                else if(j==0)
                dp[i][j]=A[i-1]==C[i-1]&&dp[i-1][j];
                else
                dp[i][j]=A[i-1]==C[i+j-1]&&dp[i-1][j]||B[j-1]==C[i+j-1]&&dp[i][j-1];
            }
        }
        return dp[A.size()][B.size()];
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends