class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int sum=0,i=0,j=0,mx=-1;
        for(auto p:nums)sum+=p;
        cout<<sum<<" ";
        sum-=x;
        cout<<sum<<" ";
        while(j<nums.size())
        {
            
            sum-=nums[j];
            // cout<<i<<" "<<j<<" "<<sum<<" ---- ";
            while(i<=j&&sum<0)
                sum+=nums[i++];
            
            if(sum==0)
            mx=max(mx,j-i+1);
            // cout<<i<<" "<<j<<" "<<sum<<" "<<mx<<endl;
            j++;
        }
        return mx==-1?-1:nums.size()-mx;
    }
};