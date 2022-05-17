class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
       int count=0,prevdiff=0,i=0,j=1,prevcount=0;
        while(j<arr.size())
        {
            if(arr[j]-arr[j-1]!=prevdiff)//means new diff
            {
                prevdiff=arr[j]-arr[j-1];
                i=j-1;
                count+=prevcount;
                prevcount=0;
            }
            else //means same diff
            {
                if(j-i+1>3)
                {
                    prevcount+=j-i-1;
                    
                }
                else if(j-i+1==3)
                {
                    prevcount=1;
                }
            }
            // cout<<count<<" "<<prevcount<<" "<<j<<endl;
            j++;
        }
        count+=prevcount;
        return count;
    }
};