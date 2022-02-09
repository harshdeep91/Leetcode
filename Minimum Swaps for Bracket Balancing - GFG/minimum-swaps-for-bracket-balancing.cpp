// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int count=0,ans=0,left=0;
         for(int i=0;i<S.size();i++)
         {
             if(S[i]=='[')
             {
                 if(count>0)
                 {
                     ans+=count;
                     count--;    
                 }
                 else
                     left++;
             }
             else
             {
                 if(left>0)
                   left--;
                   else
                   count++;
             }
         }
         return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends