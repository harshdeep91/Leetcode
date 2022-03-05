// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        //B=A+(n-1)C
        //B-A/c=n-1
        if(C==0)
        return A==B;
        double n=(double)(B-A)/C+1;
        return n>0&&(B-A)%C==0;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}  // } Driver Code Ends