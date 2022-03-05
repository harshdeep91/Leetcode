// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        int l=A[0],h=0,count,m,ma,sum,ans;
        for(int i=0;i<N;i++)
        {
            l=max(l,A[i]);
            h+=A[i];
        }
        bool flag=0;
        ans=h;
        while(l<h)
        {
            sum=0;
            count=0;
            m=(l+h)/2;
            ma=0;
            //   cout<<l<<" "<<m<<" "<<h<<" ";
            for(int i=0;i<N;i++)
            {
                sum+=A[i];
                if(sum>m)
                {
                    sum-=A[i];
                    ma=max(sum,ma);
                    count++;
                    sum=A[i];
                }
                if(i==N-1)
                {
                     ma=max(sum,ma);
                     count++;
                }
            }
            if(count==M)
            {
                flag=1;
                ans=min(ans,ma);
            }
            if(count<=M)
            h=m;
            else
            l=m+1;
            // cout<<count<<" "<<ans<<endl;
        }
       
       return h;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends