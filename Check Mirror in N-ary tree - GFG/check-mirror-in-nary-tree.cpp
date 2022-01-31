// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<int> adj1[n+1],adj2[n+1];
        for(int i=0;i<2*e;i+=2)
        {
            adj1[A[i]].push_back(A[i+1]);
            adj2[B[i]].push_back(B[i+1]);
        }
        for(int i=1;i<=n;i++)
        {
            int j=0,k=adj1[i].size()-1;
            while(j<=k)
            {
                if(adj1[i][j]!=adj2[i][k])
                return 0;
                j++;
                k--;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends