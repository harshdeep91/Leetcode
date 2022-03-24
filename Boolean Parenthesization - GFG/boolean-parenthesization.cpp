// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mod=1003;
      pair<int,int>  check(pair<int,int> &a,char x,pair<int,int> &b)
      {
          pair<int,int> ans;
        //   cout<<x<<endl;
          if(x=='^')
          {
              //T=T^F+F^T
              ans.first=((a.first*b.second)%mod+(a.second*b.first)%mod)%mod;
              //F=T^T+F^F
              ans.second=((a.first*b.first)%mod+(a.second*b.second)%mod)%mod;
              
          }
          else if(x=='&')
          {
              //T=T&T
              ans.first=(a.first*b.first)%mod;
              ans.second=((a.first*b.second)%mod+(a.second*b.first)%mod+(a.second*b.second)%mod)%mod;
          }
          else
          {
              ans.first=((a.first*b.second)%mod+(a.second*b.first)%mod+(a.first*b.first)%mod)%mod;
              ans.second=(a.second*b.second)%mod;
          }
          return ans;
      }
    int countWays(int N, string s){
        int size=N/2+1,k;
        pair<int,int> dp[size][size],ans; //first =true count //second =false count
        for(int g=0;g<size;g++)
        {
            for(int i=0,j=g;j<size;j++,i++)
            {
                if(g==0)
                {
                    if(s[2*i]=='T')
                    dp[i][j]={1,0};
                    else
                    dp[i][j]={0,1};
                }
                else if(g==1)
                {
                    dp[i][j]=check(dp[i+1][j],s[2*i+1],dp[i][j-1]);
                }
                else
                {
                    dp[i][j]={0,0};
                    for(int k=i;k<j;k++)
                    {
                       
                        ans=check(dp[i][k],s[2*k+1],dp[k+1][j]);
                        dp[i][j].first+=ans.first;
                        dp[i][j].second+=ans.second;
                        //  cout<<i<<" "<<k+1<<" "<<j<<" "<<ans.first<<" "<<ans.second<<endl;
                    }
                }
            }
        }
        // for(int i=0;i<size;i++)
        // {
        //     for(int j=0;j<size;j++)
        //     cout<<"("<<dp[i][j].first<<" , "<<dp[i][j].second<<") ";
        //     cout<<endl;
        // }
        return dp[0][size-1].first%mod;
    }
};
//35
//T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends