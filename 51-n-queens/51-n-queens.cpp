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
  void queen( vector<node> &a, int i,int n, vector<string> m, vector<vector<string>> &v)
  {
    if (i > n)
    {
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
        m[i-1][k-1]='Q';
        queen(a, i + 1,n, m, v);
        m[i-1][k-1]='.';
        a[k].col = 0;
        a[n + k - i].rdig = 0;
        a[i + k].ldig = 0;
      }
    }
  }
     vector<vector<string>> solveNQueens(int n) {
         vector<node> a(2*n+1,{0,0,0});
         string s;
         while(s.size()<n) s.push_back('.');
        vector<vector<string>> v;
        vector<string> m(n,s);
        queen(a, 1, n, m, v);
    return v;
         
    }
};