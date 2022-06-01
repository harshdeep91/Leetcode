class Solution {
public:
   void solve( vector<vector<int>>&ans,vector<int>&ds,vector<int>& nums,int i)
   {
       if(i==nums.size())
       {
           if(ds.size()>1)
           {
               ans.push_back(ds);
           }
               
           return;
       }
       if(ds.size()==0 || (nums[i]>=ds.back()))
       {
           ds.push_back(nums[i]);
           solve(ans,ds,nums,i+1);
           ds.pop_back();
       }
       if(ds.size()==0 || ds[ds.size()-1]!=nums[i]){
       solve(ans,ds,nums,i+1);}
   }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(ans,ds,nums,0);
        return ans;
    }
};