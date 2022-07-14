class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0,j=0,count=0,sum=0,zf=0,zl=0;
        //count no of zeroes before first one and after last one
        // if(goal==0)
        // {
        //     return count;
        // }
        while(j<nums.size()&&nums[i]==0)
            zf++,i++,j++;
        while(j<nums.size())
        {
            sum+= nums[j];
            zl+=(sum==goal&&nums[j]==0);
            if(sum>goal)//now count all 
            {
                if(goal==0)
                    count+= (max(zf,zl)*(max(zf,zl)+1))/2;
                else
                count+= (zf+1)*(zl+1);
                sum-=nums[i++];
                zl=0,zf=0;
                while(i<nums.size()&&nums[i]==0)
                    zf++,i++;
                // cout<<zf<<" "<<zl<<" "<<i<<" "<<j<<" "<<count<<endl;
            }
            j++;
        }
        if(sum==goal)
        {
            cout<<zf<<" "<<zl<<" "<<count<<endl;
            if(goal==0)
                count+= (max(zf,zl)*(max(zf,zl)+1))/2;
            else
            count+= (zf+1)*(zl+1);
        }
        return count;
    }
};