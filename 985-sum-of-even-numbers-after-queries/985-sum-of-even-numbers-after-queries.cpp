class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0,prev;
        vector<int> ans;
        for(auto x:nums)sum+= (x%2==0?x:0);
        for(auto x:queries)
        {
            prev=nums[x[1]];
            nums[x[1]]+= x[0];
            //if value become even after odd then add the whole value
            //if value becomes odd after even then subtract the prev value
            //if value becomes even after even then add only the new part
            if(prev&1)//means  add the whole value
            {
                if(nums[x[1]]%2==0)
                sum+=nums[x[1]];
            }
            else //means previous is even
            {
                if(nums[x[1]]&1)//new is odd then subtract the whole prev
                    sum-= prev;
                else
                    sum+= x[0];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};