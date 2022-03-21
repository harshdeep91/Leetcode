// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        long long  curr=0,prev=k*k,prevprev=k,mod=pow(10,9)+7;
        if(n==1)
        return k;
        for(int i=3;i<=n;i++)
        {
            // cout<<i<<" = "<<curr<<endl;
            curr=((k-1)*(prev+prevprev))%mod;
            prevprev=prev;
            prev=curr;
            // if(i%2==0)
            // count+=k;
        }
        return prev;
    }
};
// " "<<prev<<" "<<prevprev<<


// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends