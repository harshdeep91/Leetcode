// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int jump=arr[0],steps=0,mxdis=0,count=0,i=1;
        // cout<<count<<" "<<arr[0]<<endl;
        while(i<n)
        {
            count++;
            while(i<n&&jump--)
            {
                if(i+arr[i]>mxdis)
                {
                    mxdis=i+arr[i];
                    // steps=arr[i]-i+1;
                }
                // cout<<count<<" "<<mxdis<<" "<<arr[i]<<endl;
                i++;
            }
            jump=mxdis-i+1;
            // cout<<jump<<endl;
            if(jump<=0)
            return -1;
        }
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends