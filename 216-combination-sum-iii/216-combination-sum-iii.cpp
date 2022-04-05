class Solution {
public:
    void solve(int i,int k,int n,vector<vector<int>> &ans,vector<int> v)
    {
        if(i==10||k==0||n==0)//base case
        {
            if(k==0&&n==0)
                ans.push_back(v);
            return;
        }
        v.push_back(i);
        solve(i+1,k-1,n-i,ans,v);
        v.pop_back();
        solve(i+1,k,n,ans,v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>> ans;
        solve(1,k,n,ans,{});
        return ans;
    }
};