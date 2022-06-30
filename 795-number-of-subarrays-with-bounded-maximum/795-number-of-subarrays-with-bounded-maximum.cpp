class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    //if max ith element is out of range then we
    //start new  array from i+1
    int count=0,i=0,j=0,mx=0,prev=0;
    while(j<nums.size())
    {
        mx=max(nums[j],mx);
        //for low value that are out of range we need some type of counter 
        if(mx>=left&&mx<=right)//in range
        {
            if(nums[j]>=left&&nums[j]<=right)//in range add new array
            {
                count+= j-i+1;
                prev=j-i+1;
            }
            else 
                count+=prev;
            // cout<<mx<<" "<<nums[j]<<" "<<count<<endl;
        }
        else if(nums[j]<=right)//they could be included 5 6 7 range 7 to 7
        {
          // i=j+1;
            mx=0;
            prev=0;
            if(nums[i]>right)//then dont include new value;
                i=j;
        }
        else 
        {
            i=j+1;
            mx=0;
            prev=0;
        }
        j++;
    }
    return count;
    }
};