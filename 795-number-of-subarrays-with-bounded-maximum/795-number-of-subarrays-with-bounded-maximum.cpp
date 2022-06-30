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
                     prev=j-i+1;
                    count+=prev; //because of case 4 5 2 3 range 4 to 5 we cant add [2 3] and [2],[3]
            }
            else 
            {
                if(nums[j]>right)
                  i=j+1;
                else if(nums[i]>right)//they could be included 5 6 7 range 7 to 7
                    i=j;
                mx=0;
                prev=0;
            }
            j++;
        }
        return count;
    }
};