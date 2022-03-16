// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
 int solve(int i,vector<vector<bool>> &dp,vector<int>&count)
        
        {
            // cout<<A.size()<<endl;
            if(i==dp.size())
            {
                return -1;
            }
            int j=i,mi=INT_MAX;
            while(j<dp.size())
            {
                
                // cout<<i<<" "<<j<<" "<<mi<<" "<<dp[i][j]<<endl;
                if(dp[i][j])
                {
                    if(count[j+1]==-1)
                    count[j+1]=solve(j+1,dp,count)+1;
                    
                    mi=min(mi,count[j+1]);
                }
                j++;
            }
            return mi;
        }
    int palindromicPartition(string s)
    {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),0));
        for(int g=0;g<s.size();g++)
        {
            for(int i=0,j=g;j<s.size();i++,j++)
            {
                if(g==0)
                    dp[i][j]=1;
                else if(g==1)
                    dp[i][j]=s[i]==s[j];
                else
                    dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1])?1:0;
            }
        }
        vector<int> count(s.size()+1,-1);
       return solve(0,dp,count);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends