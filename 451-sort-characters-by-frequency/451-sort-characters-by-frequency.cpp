class Solution {
public:
    static bool cmp(pair<int,char> &a,pair<int,char> &b){
        if(a.first>b.first||(a.first==b.first&&a.second<b.second))
            return true;
        return false;
    }
    string frequencySort(string s) {
        vector<pair<int,char>> v(256,{0,'*'});
        for(auto x:s)
        {
            v[x].first=v[x].first+1;
            v[x].second=x;
        }
        s.clear();
        sort(v.begin(),v.end(),cmp);
        for(auto x:v)
        {
            if(x.first==0) return s;
            while(x.first--)    s+=x.second;
        }
        return s;
    }
};