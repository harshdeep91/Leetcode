class Solution {
public:
    int solve(int av,vector<int>& nums)
    {
        long long i=0,count=0;
        while(i<nums.size())
            count+=abs(nums[i++]-av);
        // cout<<av<<" "<<count<<endl;
        return count;
    }
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),m,l=nums[0],h=nums.back(),mh,ml,mm;
        // for(int i=0;i<n;i++)
        // {
        //     h+=nums[i];
        //     l=min(l,nums[i]);
        // }
        // // cout<<av<<" "<<nums.size();
        //  h=h/n+1;
        while(l<=h)
        {
             m=(l+h)>>1;
            // cout<<l<<" "<<m<<" "<<h<<endl;
             ml=solve(m-1,nums);
             mm=solve(m,nums);
             mh=solve(m+1,nums);
             if(ml<=mm)
                 h=m-1;
             else
                l=m+1;
        }
        // cout<<ml<<" "<<mh<<endl;
       // cout<<av; 
        return min(ml,min(mm,mh));
    }
};