class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        m[0]=-1;
        int mx=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]?1:-1);
            if(m.find(sum)==m.end())
                m[sum]=i;
            mx=max(mx,i-m[sum]);
        }
        return mx;
    }
};