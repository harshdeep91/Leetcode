class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        
        int k=nums.size();
        while(k>1)
        {
            
            bool even=1;
                for(int i=0;i<k/2;i++)
            {
                if(even)
                nums[i]=min(nums[2*i],nums[2*i+1]);
                else
                 nums[i]=max(nums[2*i],nums[2*i+1]);
                    even=!even;
                    
            }
            // for(int i=0;i<k;i++)
            //     cout<<nums[i]<<" ";
            k/=2;
            // cout<<k<<" "<<nums[0]<<endl;
            // cout<<endl;
        }
        
        return nums[0];
    }
};