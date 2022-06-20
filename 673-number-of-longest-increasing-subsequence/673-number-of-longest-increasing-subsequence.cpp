class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //pair count how many times it appearss and len
        vector<int> len(nums.size(),1),count(nums.size(),1);
        int mx=1,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i])
                {
                    if(len[j]<len[i]+1)
                    {
                        count[j]=count[i];
                        len[j]=len[i]+1;
                        mx=max(len[j],mx);
                    }
                    else if(len[j]==len[i]+1)count[j]+=count[i];
                }
            }
        }
        
        //travel len and count
        // cout<<mx<<endl;
        for(int i=0;i<nums.size();i++)
        {
            if(len[i]==mx)
            {
                // cout<<nums[i]<<" "<<len[i]<<" "<<count[i]<<endl;
                ans+=count[i];
            }
        }
        return ans;
    }
};