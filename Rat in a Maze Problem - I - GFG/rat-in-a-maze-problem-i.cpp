// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int>> mat;
    vector<string> ans;
    int N;
    void solve(int i,int j,string s)
    {
        if(i==N-1&&j==N-1&&mat[i][j])
        {
            ans.push_back(s);
            return;
        }
        if(i>=0&&i<N&&j>=0&&j<N&&mat[i][j]==1)
        {
            mat[i][j]=0;
           solve(i-1,j,s+"U");
           solve(i+1,j,s+"D");
           solve(i,j-1,s+"L");
           solve(i,j+1,s+"R");
           mat[i][j]=1;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        mat=m;
        ans.clear();
        N=n;
        solve(0,0,"");
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends