class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        //find the every possilbe difference 
        //then check one by one like lis
        //we can use unordered_map for every difference
        //difference could range from -500 to 500
        //we can shift the differenc by adding 500
        vector<vector<int>> m(nums.size(),vector<int>(1001,0));
        int diff,ans=1;
        //find every possible difference
        for(int i=nums.size()-1;i>=0;i--)
        {
            // cout<<nums[i]<<"--> ";
            for(int j=i+1;j<nums.size();j++)
            {
                //we can check if difference exist or not 
                //if exist simply add the value
                //anything coming for first would be added with 2
                //and if anything already exist on other value
                //then simply add
                diff=nums[i]-nums[j]+500;
                if(m[i][diff]==0)m[i][diff]=1;
                m[i][diff]=max(m[i][diff],(m[j][diff]?m[j][diff]:1)+1);
                ans=max(ans,m[i] [diff]);
                // cout<<" ( "<<nums[j]<<","<<diff<<" ) ";
            }
            // cout<<ans<<endl;
        }
       //  for(int i=0;i<nums.size();i++)
       //  {
       //      cout<<nums[i]<<"--> ";
       //      for(auto x:m[i])
       //      {
       //          cout<<x.first<<" "<<x.second<<" -- ";
       //      }
       //      cout<<endl;
       // }
        return ans;
    }
};