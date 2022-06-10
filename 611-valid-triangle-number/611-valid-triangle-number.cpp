class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //for one to be a traingle it should follow a+b<c for all side
        //if we sort we only need to check big side with smaller one if that is correct then all is correct
        // now  choose i first then select j and k carefully
        //if nums[i]+nums[j]>nums[k] it means all before k will follow traingle properties so we increase k count to get last traingle
        // if nums[i]+nums[j]<=nums[k] it means here we need to calculate all possible traingles [j,k) => k-j-1 (-1 because of increase of k)
        //now increase j 
        //after finishing k==n we need to again count all possible traingle that can be made
        // 2,3,4,4 in this example i=0,j=1,k=4 now k-j++ will give 2 but it should be 3 because 2,4,4 is not counted
        
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
                    count+=k- ++j;
            }
            if(++j<k)
               count+= ((k-j)*(k-j+1))/2;
        }
        // [6,16,24,24,29,44]
        return count;
    }
    
};