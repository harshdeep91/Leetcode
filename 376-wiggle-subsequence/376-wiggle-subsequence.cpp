
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int mi = 1, ma = 1;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i+1]-nums[i]>0)
            {
                ma = mi + 1;
            }
            else if(nums[i+1]-nums[i]<0){
                mi = ma + 1;
            }
            // cout << mi << " " << ma << endl;
        }
        return max(mi,ma);
    }
};