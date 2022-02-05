// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n=nums.size();
        int dp[n];
        int sum=0;
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            int cl=-1;
            dp[i]=INT_MAX;
            for(int j=i;j<n;j++)
            {
                cl+=(nums[j]+1);
                if(cl>k)
                break;
                if(j==n-1)
                sum=0;
                else
                sum=(k-cl)*(k-cl)+dp[j+1];
                dp[i]=min(dp[i],sum);
            }
        }
        return dp[0];
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends