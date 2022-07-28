class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //find first min from right
        //if any number not satify it then min index is end and number index is s
        
        int n=nums.size(), mi=nums[n-1],e=-1,s=-1,index=n-1,mx=nums[0];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=mi)//update mi
                mi=nums[i],index=i;
            else //means we got the new size
            {
                if(e==-1)e=index;
                s=i;
            }
        }
        // cout<<s<<" "<<e<<endl;
        //find first max from left
        index=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=mx)//update mx
                mx=nums[i],index=i;
            else //means we got the new size
            {
                if(s==-1)s=index,e=i;
                else
                    s=min(s,index),e=max(e,i);
            }
        }
        // cout<<s<<" "<<e<<endl;
        return e==-1?0:e-s+1;
    }
};