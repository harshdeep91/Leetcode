class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int m=(l+h)>>1;
            // cout<<m<<" "<<l<<" "<<h<<endl;
            if(m+1<=h&&nums[m]==nums[m+1])
            {
                if((m-l)%2==0)
                    l=m+2;
                else
                    h=m-1;
            }
            else if(m-1>=l&&nums[m]==nums[m-1])
            {
                // cout<<h-m<<" ";
                if((h-m)%2==0)
                    h=m-2;
                else
                    l=m+1;
            }
            else return nums[m];
        }
        return 0;
    }
};