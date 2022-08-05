class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[0]<b[0] || (a[0]==b[0]&&a[1]>b[1]);
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        //so after drawing graph we found out that
        //we should start from smallest and include 
        //those intervals which going max
        //we will check if we able to cover the interval or not
        //from end time if not we will include that interval
        sort(clips.begin(),clips.end(),cmp);
        int s=clips[0][0],e=clips[0][1],count=1,i=1,end;
        if(s!=0)return -1;
        if(e>=time)return 1;
        // for(auto x:clips)
        //     cout<<x[0]<<" "<<x[1]<<endl;
        while(i<clips.size())
        {
            //include max end time interval that is overlapping with curr interval
            if(clips[i][0]>e)return -1;
            end=clips[i][1];
            while(i<clips.size()&&clips[i][0]<=e)
                end=max(end,clips[i++][1]);
            count++;
            e=end;
            cout<<s<<" "<<e<<" "<<count<<endl;
            //check if we able to reach the target
            if(e>=time)return count;
            // i++;
        }
        
        return -1;
    }
};