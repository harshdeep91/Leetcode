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
                    mx=max(count,mx);
                    count=2; 
                    dec=0;
                    inc=1;
                }
                else{
                  inc=1;
                    count++;
                } 
            }
            else if(arr[i]<arr[i-1])//decreasing
            {
                if(inc==1)//means decreasing trend started this might me mountain
                {
                    count++;
                    dec=1;
                }
                else //start fresh 
                {
                    inc=0;
                    dec=0;
                    count=1;
                }
            }
            else //equal case
            {
                mx=max(inc&&dec?count:0,mx);
                inc=0;
                dec=0;
                count=1;
            }
                // cout<<arr[i]<<" "<<inc<<" "<<dec<<" "<<count<<" "<<mx<<endl;
        }
        mx=max(inc&&dec?count:0,mx);
        return mx>=3?mx:0;
    }
};