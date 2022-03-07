// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int mod=1000000007,c;
	int solve(vector<vector<int>> &dp,int one,int zero,int count)
	{
	   // cout<<one<<" "<<zero<<" "<<count<<endl;
	    if(count==0)
	    {
	        
	        if(one==zero)
	        {
	           // cout<<s<<endl;
	           
	            return 1;
	        }
	        return 0;
	    }
	    //one
	    int x=0,y=0;
	   // string key=to_string(one)+"*"+to_string(zero)+"*"+to_string(count);
	    if(one<=c)
	    {
	        if(dp[one][zero]==-1)
	    {
	        if(one>zero)
	        x=solve(dp,one,zero+1,count-1);
	        y=solve(dp,one+1,zero,count-1);
	    }
	    else
	    return dp[one][zero];
	    }
	    else
	    return 0;
	    return dp[one][zero]=((x+mod)%mod+(y+mod)%mod)%mod;
	    
	}
	int prefixStrings(int N)
	{
	    // Your code goes here
	   // unordered_map<string,pair<bool,int>> dp;
	   c=N;
	   vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
	   //cout<<dp.size()<<" "<<dp[0][0];
	   //for(int i=0;i<=N;i++)
	   // for(int j=0;j<=N;j++)
	   // dp[i][j]=-1;
	   // cout<<dp[0][0]<<endl;
	    return solve(dp,0,0,N*2);
	   // return 0;
	    //one>zero
	    
	   // int one=1,zero=0,prev=1,curr=0,dp[2*N+1];
	   // dp[0]=0;
	   // dp[1]=1;
	   // for(int i=2;i<=2*N;i++)
	   // {
	   //    // curr=prev;
	   //    cout<<one<<" "<<zero<<endl;
	   //    dp[i]=(one<N)?dp[i-1]:0;//for one
	   //           if(one>zero)
	   //         {
	                
	   //           zero++;
	   //           dp[i]+=dp[i-1];
	   //         }
	   //       else if(one<N)
	   //         {
	   //            // dp[i]+=1;
  	 //          //  curr+=zero;
	   //          one++;
	   //         }
	   //        // prev=curr;
	   //        // cout<<curr<<" ";
	   //        cout<<dp[i]<<" "<<one<<" "<<zero<<endl;
	   // }
	   // cout<<endl;
	   // return dp[2*N];
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
        cout << ob.prefixStrings(n);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends