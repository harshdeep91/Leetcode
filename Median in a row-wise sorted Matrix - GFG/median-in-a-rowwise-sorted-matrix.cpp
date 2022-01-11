// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
int median(vector<vector<int>> &matrix, int r, int c){

      int mi=matrix[0][0],mx=matrix[r-1][c-1],mid,count=0,req=r*c/2+1;
       for(int i=0;i<r;i++)
       {
          mi=min(mi,matrix[i][0]);
          mx=max(mx,matrix[i][c-1]);
       }
       while(mi<mx)
       {
           mid=(mi+mx)/2;
        //   cout<<mi<<" "<<mx<<" "<<mid<<" ";
           count=0;
           for(int i=0;i<r;i++)
           count+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
        //   cout<<count<<endl;
           if(count<req)
           mi=mid+1;
           else
           mx=mid;
       }
       return mi;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends