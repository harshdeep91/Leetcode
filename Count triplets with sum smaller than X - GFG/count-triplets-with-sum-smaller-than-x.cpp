// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	     sort(arr,arr+n);
	     int i=0,j,k;
	     long long x,count=0;
	     while(i<n-2)
	     {
	         j=i+1;
	         k=n-1;
	         while(j<k)
	         {
	             x=arr[i]+arr[j]+arr[k];
	             if(x>=sum)
	             k--;
	             else
	              {
	                  count+=k-j;
	                  j++;
	              }
	         }
	         i++;
	     }
	    return count;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends