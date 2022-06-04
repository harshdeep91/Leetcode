struct node
  {
    bool col, rdig, ldig;
  };
class Solution{
public:

  bool isvalid( vector<node> &a, int i, int j, int n)
  {
    if (i > 0 && i <= n && j > 0 && j <= n && !a[j].col && !a[n + j - i].rdig && !a[i + j].ldig)
      return 1;
    return 0;
  }
  void queen( vector<node> &a, int i, int j, int n, vector<int> m, vector<vector<int>> &v)
  {
    if (i > n)
    {
      if (m.size() ==n)
        v.push_back(m);
      return;
    }
    for (int k = 1; k <= n; k++)
    {
      if (isvalid(a, i, k, n))
      {
        a[k].col = 1;
        a[n + k - i].rdig = 1;
        a[i + k].ldig = 1;
        m.push_back(k);
        queen(a, i + 1, k, n, m, v);
        m.pop_back();
        a[k].col = 0;
        a[n + k - i].rdig = 0;
        a[i + k].ldig = 0;
      }
    }
  }
     vector<vector<string>> solveNQueens(int n) {
         vector<node> a(2*n+1,{0,0,0});
    vector<vector<int>> v;
    vector<int> m;
    queen(a, 1, 0, n, m, v);
         // for(auto x:v)
         //     for(auto i:x)
         //         cout<<i<<" ";
         string s;
         while(s.size()<n)
             s.push_back('.');
         vector<vector<string>> ans(v.size(),vector<string>(n,s));
         for(int i=0;i<v.size();i++)
             for(int j=0;j<n;j++)
                 ans[i][j][v[i][j]-1]='Q';
    return ans;
         
    }
};