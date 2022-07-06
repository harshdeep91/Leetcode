class Solution {
public:
    int carFleet(int tt, vector<int>& p, vector<int>& s) {
        vector<pair<int,int>> v;
        for(int i=0;i<p.size();i++)
            v.push_back({p[i],s[i]});
        sort(v.begin(),v.end());
        //travel from behind if we encounter new min simply count++
        int count=0,mi=INT_MAX;
        double t=0,target=tt;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i].first+t*v[i].second<target)
            {
                count++;
                // mi=v[i].second;
                t= ((target-v[i].first))/(double)v[i].second;
            }
            // cout<<i<<" "<<mi<<" "<<t<<" "<<count<<endl;
        }
        return count;
    }
};