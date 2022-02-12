// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    bool check(string &A, string &B)
    {
        int a[256]={0};
        if(A.size()!=B.size())
        return 0;
        for(int i=0;i<B.size();i++)
        {
            a[A[i]]++;
            a[B[i]]--;
        }
        for(int i=0;i<256;i++)
        {
            if(a[i])
            return 0;
        }
        // reverse(A.begin(),A.end());
        // reverse(B.begin(),B.end());
        
        return 1;
    }
    int transform (string A, string B)
    {
        
        if(!check(A,B))
        return -1;
        int i=A.size()-1,j=B.size()-1,count=0;
        while(i>=0)
        {
            if(A[i]==B[j])
                j--;
            else
                count++;
            i--;
        }
        return count;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends