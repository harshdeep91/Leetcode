// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int countBT(int h) { 
    long long int prev=15,prevprev=3,curr,mod=pow(10,9)+7;
        if(h==1)
        return 1;
        else if(h==2)
        return 3;
        for(int i=4;i<=h;i++)
        {
            curr=((2*(prev*prevprev))%mod+(prev*prev)%mod)%mod;
            prevprev=prev;
            prev=curr;
        }
        return prev;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends