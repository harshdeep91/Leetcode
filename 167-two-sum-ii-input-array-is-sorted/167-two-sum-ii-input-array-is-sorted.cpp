class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,n=numbers.size(),j=n-1;
        while(i<j)
        {
            if(numbers[i]+numbers[j]==target)
                break;
            else if(numbers[i]+numbers[j]<target)
                i++;
            else
                j--;
        }
        return {i+1,j+1};
    }
};