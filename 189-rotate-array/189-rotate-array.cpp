class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        int req=n-k;
        vector<int> v(nums.begin()+req,nums.end());
        for(int i=0;i<req;i++)
        v.push_back(nums[i]);
        for(int i=0;i<n;i++)
            nums[i]=v[i];
    }
};