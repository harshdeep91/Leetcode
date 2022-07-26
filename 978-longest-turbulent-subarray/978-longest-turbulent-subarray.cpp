class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int greater,tmp,less,ans=1,countg=1,countl=1;
        // greater=less=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            //for greater we need less<arr[i]
            //if exist do it otherewise reset
             tmp=arr[i-1]<arr[i]?countl+1:1;
             // greater=arr[i];
             countl=arr[i-1]>arr[i]?countg+1:1;
             countg=tmp;
            // cout<<arr[i]<<" "<<count
             ans=max(ans,max(countg,countl));
            //
        }
        return ans;
    }
};