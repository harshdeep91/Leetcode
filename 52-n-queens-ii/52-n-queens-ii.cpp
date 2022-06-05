
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
  void queen( vector<node> &a, int i,int n, int &count)
  {
    if (i > n)
    {
        count++;
      return;
    }
    for (int k = 1; k <= n; k++)
    {
      if (isvalid(a, i, k, n))
      {
        a[k].col = 1;
        a[n + k - i].rdig = 1;
        a[i + k].ldig = 1;
        queen(a, i + 1,n, count);
        a[k].col = 0;
        a[n + k - i].rdig = 0;
        a[i + k].ldig = 0;
      }
    }
  }
     int totalNQueens(int n) {
             int count=0;
         vector<node> a(2*n+1,{0,0,0});
        queen(a, 1, n,count);
    return count;
    }
    
};