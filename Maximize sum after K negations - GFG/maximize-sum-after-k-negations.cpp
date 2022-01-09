// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        long long int i=0,sum=0,mi=INT_MAX;
        sort(a,a+n);
        while(i<n)
        {
            if(a[i]<=0&&k)
            {
                k--;
                a[i]=-a[i];
            }
            mi=min(a[i],mi);
            sum+=a[i];
            i++;
        }
           if(k&1)
            sum-=2*mi;
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends