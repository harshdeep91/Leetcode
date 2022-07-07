class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //first is increasing then it is decreasing //it is given that length is 3 so we dont get any problem
        int l=0,h=arr.size()-1,m;
        while(l<=h)
        {
            m=(l+h)>>1;
            //check if m
            if(m-1<0||arr[m]>arr[m-1])//means move forward
                l=m+1;
            else
                h=m-1;
        }
        return h;
    }//0 5 => 2 =>
};