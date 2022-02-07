// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string s)
    {
        int n=s.size(),j;
       long long int dp[n][n],mod=pow(10,9)+7;
       for(int g=0;g<n;g++)
       {
           for(int i=0;i+g<n;i++)
           {
              j=i+g;
              if(g==0)
              {
                  dp[i][j]=1;
              }
              else if(g==1)
              {
                  dp[i][j]=s[i]==s[j]?3:2;
              }
              else
              {
                  dp[i][j]=s[i]==s[j]?1:-dp[i+1][j-1];
                  dp[i][j]=(((dp[i][j]+mod)%mod+dp[i][j-1])%mod+dp[i+1][j])%mod;
              }
           }
       }
       return dp[0][n-1];
    }
     
};
// mbcgepnkdqemhmkuqosgeonbcrphobcmbhrgppkfpdqckigsomktpsurknsospighufulqijcupisnuqcqfpuckrndmqeeklqfcrfnemeghmnlunlpslncqllmbebnoudihgpigrfbrqbcurmqnfroheqltkbnpocousjepehgppmblodppsqrglprtekmsqlqekhjseotocgkfcrkssmmenhitupdcoujscnetbrrcdoctqdfssupfnuolrobckseuromqsuoctmnbudnthrctndtrnietrkqbropugptpuhclftohuendhhnpnhqqkmksigbcrtrtjtmhonnumnnupgtntdhefushmrshselrdfqnoddmqqhjrjtknmokrlgdrcomnbjdlcothrhgsljreflusnnnrkckstoluhduguicfomgjkorgmujoonekscbikeshbqfqfrbcmspqphujltqebostmbkunhhhqmdqdqmfsbek


// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends