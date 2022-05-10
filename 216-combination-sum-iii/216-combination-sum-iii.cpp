class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int k,int n,vector<int> &v)
    {
        if(i==10||k==0||n==0)//base case
        {
            if(k==0&&n==0)
                ans.push_back(v);
            return;
        }
        v.push_back(i);
        solve(i+1,k-1,n-i,v);
        v.pop_back();
        solve(i+1,k,n,v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         ans.clear();
        vector<int> v;
        solve(1,k,n,v);
        return ans;
    }
};