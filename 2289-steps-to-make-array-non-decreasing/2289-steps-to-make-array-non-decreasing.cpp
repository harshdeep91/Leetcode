class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>> s;
        int count=0,mx=0,ms;
        for(int i=nums.size()-1;i>=0;i--)
        {
            count=0,ms=0;
             if(!s.empty()&&s.top().first<nums[i])
            {
                while(!s.empty()&&s.top().first<nums[i])
                {
                    count=max(count+1,s.top().second);
                    s.pop();
                }
            }
            mx=max(count,mx);
            // cout<<nums[i]<<" "<<count<<endl;
            s.push({nums[i],count});
        }
        return mx;
    }
};