class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),count=0,k,j;
        for(int i=0;i<n-2;i++)
        {
            j=i+1,k=i+2;
            while(k<n)
            {
                // cout<<i<<" "<<j<<" "<<k<<" "<<count<<endl;
                if(j>=k||nums[i]+nums[j]>nums[k])
                    k++;
                else
                {
                    j++;
                    // count+= ((k-j)*(k-j+1))/2;
                    count+=k-j;
                }
            }
            while(j<k)
            {
                    j++;
                    count+=k-j;
            }
        }
        // [6,16,24,24,29,44]
        return count;
    }
};