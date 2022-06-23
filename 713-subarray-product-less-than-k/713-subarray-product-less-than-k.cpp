class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0,count=0,prod=1;
        //if k is zero then nums must have zero in it
        if(k==0)return 0;
        while(j<nums.size())
        {
            prod*=nums[j];
            while(i<j&&prod>=k)prod/=nums[i++];
            if(prod<k) count+= j-i+1;
            j++;
        }
        return count;
    }
};