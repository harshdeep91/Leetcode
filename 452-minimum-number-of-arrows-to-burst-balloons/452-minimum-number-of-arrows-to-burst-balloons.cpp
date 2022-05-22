class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[1]<b[1]||(a[1]==b[1]&&a[0]<b[0]))
            return 1;
        return 0;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int s=points[0][0],e=points[0][1],count=1;
        for(int i=1;i<points.size();i++)
        {
            // cout<<e<<" "<<count<<endl;
            if(points[i][0]>e)
            {
                count++;
                e=points[i][1];
            }
        }
        
        return count;
    }
};