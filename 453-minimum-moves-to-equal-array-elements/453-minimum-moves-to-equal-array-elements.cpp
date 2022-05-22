class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
             count+= nums[i]-nums[0];
        }
        return count;
    }
};

//brute force every time choose min and max and count+=max-min and update array with max-min 