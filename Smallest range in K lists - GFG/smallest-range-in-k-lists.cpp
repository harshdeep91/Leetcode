// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
         int mx=INT_MAX,l=arr[0][0],h=arr[0][0],ansh;
         for(int i=0;i<k;i++)
             {
                 q.push({arr[i][0],{i,0}});
                 h=max(arr[i][0],h);
             }
          while(q.size()==k)
          {
              int el=q.top().first;
              int row=q.top().second.first;
              int col = q.top().second.second;
              q.pop();
              if(h-el<mx)
              {
                  l=el;
                  mx=h-el;
                  ansh=h;
              }
              col++;
              if(col<n)
              {
                  h=max(arr[row][col],h);
                  q.push({arr[row][col],{row,col}});
              }
             // cout<<el<<" "<<l<<" "<<h<<endl;
          }
         return {l,ansh};
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
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends