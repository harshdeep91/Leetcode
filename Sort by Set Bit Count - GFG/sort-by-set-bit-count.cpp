// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

  
class Solution{
    public:
  int setbit(int x)
    {
        int count=0,j=1,k;
        while(x)
        {
            count+=x&1?1:0;
            x/=2;
        }
        return count;
    }
    static bool cmp(pair<int,int> A,pair<int,int> B)
    {
        if(A.first>B.first )
        return 1;
        return 0;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        int count;
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)
        {
            count=setbit(arr[i]);
            a.push_back({count,arr[i]});
        }
        stable_sort(a.begin(),a.end(),cmp);
        for(int i=0;i<n;i++)
        {
            // cout<<a[i].first<<" "<<a[i].second<<endl;
            arr[i]=a[i].second;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends