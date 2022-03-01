// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int lowerbound(int arr[],int n,int x)
{
    int l=0,h=n-1,m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(arr[m]<x)
        l=m+1;
        else
        h=m-1;
    }
    return l;
}
int upperbound(int arr[],int n,int x)
{
    int l=0,h=n-1,m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(arr[m]<=x)
        l=m+1;
        else
        h=m-1;
    }
    return l;
}
vector<int> find(int arr[], int n , int x )
{
    int l=lowerbound(arr,n,x);
    // cout<<l<<endl;
    int h=upperbound(arr,n,x);
    // cout<<h<<endl;
    h--;
    if(l>h)
    return {-1,-1};
    else
    return {l,h};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends