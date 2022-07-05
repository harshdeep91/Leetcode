class Solution {
public:
    int longestMountain(vector<int>& arr) {
       //if decreasing trend started with no increasing start from this index
        //if after increasing decreasing trend started then continue
        bool inc=0,dec=0;
        int count=1,mx=0;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>arr[i-1])//increasing
            {
                if(dec==1)//means decreasing trend is coming start fresh
                {
                    count=1; 
                    dec=0;
                }
                inc=1;
            }
            else if(arr[i]<arr[i-1])//decreasing
            {
                if(inc==1)//means decreasing trend started this might me mountain
                {
                    dec=1;
                }
                else //start fresh 
                {
                    inc=0;
                    dec=0;
                    count=0;
                }
            }
            else //equal case
            {
                inc=0;
                dec=0;
                count=0;
            }
                count++;
            mx=max(inc&&dec?count:0,mx);
        }
        
        return mx>=3?mx:0;
    }
};