class Solution {
    vector<vector<int>> v;
public:
     static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]<b[0]||(a[0]==b[0]&&a[1]<b[2]))
            return 1;
        return 0;
    }
    int upperbound(int x)
    {
        int l=x,h=v.size()-1;
        while(l<=h)
        {
            int m=(l+h)>>1;
            if(v[m][0]<v[x][1])//start at m< end at x
                l=m+1;
            else
                h=m-1;
        }
        return l;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        v.clear();
        vector<int> ans(intervals.size(),-1);
        for(int i=0;i<intervals.size();i++)
            v.push_back({intervals[i][0],intervals[i][1],i});
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<intervals.size();i++)
        {
                 int j=upperbound(i);
                if(j<intervals.size())
                {
                    // cout<<v[i][0]<<" "<<v[i][1]<<endl;
                    ans[v[i][2]]=v[j][2];
                }
        }
        return ans;
    }
};