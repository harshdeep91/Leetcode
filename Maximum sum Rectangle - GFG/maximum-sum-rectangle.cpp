// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mx;
  void kadane(vector<int> &a)
  {
      int sum=0;
      for(int i=0;i<a.size();i++)
      {
          sum+=a[i];
             mx=max(sum,mx);
          if(sum<0)
              sum=0;
           
      }
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        mx=INT_MIN;
        for(int r=0;r<R;r++)
        {
            vector<int> a(C,0);
            for(int i=r;i<R;i++)
            {
                for(int j=0;j<C;j++)
                {
                    a[j]+=M[i][j];
                }
                kadane(a);
            }
        }
        return mx;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends