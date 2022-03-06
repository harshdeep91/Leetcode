// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // n-1Cr-1+n-1Cr=nCr;
        // cout<<n<<" "<<r<<endl;
        // if(r>n)
        // return 0;
        // if(n==r||n==0||r==0)
        // return 1;
        // return (nCr(n-1,r-1)+nCr(n-1,r)+mod)%mod;
        
        
           int mod = 1000000007;
        int C[r+1];
        memset(C, 0, sizeof(C));
        
        C[0] = 1;
    	for (int i = 1; i <= n; i++) { 
    		for (int j = min(i, r); j > 0; j--){ 
                // nCj = (n-1)Cj + (n-1)C(j-1); 
    			C[j] = (C[j] + C[j-1])%mod;
    		}
    	} 
    	return C[r]%mod;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends