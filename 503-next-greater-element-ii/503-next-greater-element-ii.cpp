class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,INT_MIN);
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!s.empty()&&nums[i]>=s.top())
                s.pop();
            if(!s.empty())
                ans[i%n]=max(ans[i%n],s.top());
            s.push(nums[i]);
        }
        for(int i=0;i<n;i++)
            if(ans[i]==INT_MIN)ans[i]=-1;
        return ans;
    }
};