class Solution {
public:
    int minMoves(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int count=0,mi=INT_MAX;
        for(int i=0;i<nums.size();i++)
            mi=min(mi,nums[i]);
            for(int i=0;i<nums.size();i++)
             count+= nums[i]-mi;
        return count;
    }
};

//brute force every time choose min and max and count+=max-min and update array with max-min 