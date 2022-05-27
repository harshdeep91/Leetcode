class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int a[32]={0},count=0,x,pos,n=nums.size();
        for(int i=0;i<n;i++)
        {
            x=nums[i],pos=31;
            while(x)
            {
                a[pos--]+=x&1;
                x>>=1;
            }
        }
        for(int i=0;i<32;i++)
            count+=(a[i]*(n-a[i]));
            // cout<<a[i];
        // cout<<endl;
        return count;
    }
    
};