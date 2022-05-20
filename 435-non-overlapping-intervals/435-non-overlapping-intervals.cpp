class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[1]<b[1]||(a[1]==b[1]&&a[0]<b[0]))
            return 1;
        return 0;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int s=INT_MAX,e=-1,count=0;
        for(auto x:intervals)
        {
            // cout<<x[0]<<" "<<x[1]<<endl;
            if(s==INT_MAX||x[0]>=e)
            {
                s=x[0],e=x[1];
            }
            else // overlap
             count++;
        }
        return count;
    }
};