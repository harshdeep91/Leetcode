class Solution {
public:
    static bool cmp(pair<int,string> &a,pair<int,string> &b)
    {
        return a.first>b.first||(a.first==b.first&&a.second<b.second);
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto x: words)m[x]++;
        vector<pair<int,string>> p;
        for(auto x:m)p.push_back({x.second,x.first});
        sort(p.begin(),p.end(),cmp);
        vector<string> ans;
        for(int i=0;i<k;i++)
            ans.push_back(p[i].second);
        return ans;
    }
};