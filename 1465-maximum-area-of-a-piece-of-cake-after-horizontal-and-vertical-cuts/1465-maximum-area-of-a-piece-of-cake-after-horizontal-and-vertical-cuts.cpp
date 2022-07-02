class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& v) {
        //we can do it by simply storing max values by row and column
        ho.push_back(0);//for easily finding mx
        v.push_back(0);
        ho.push_back(h);
        v.push_back(w);
        sort(ho.begin(),ho.end());
        sort(v.begin(),v.end());
        int mr=0,mc=0,mod=1e9+7;
        for(int i=1;i<ho.size();i++)
            mr=max(mr,ho[i]-ho[i-1]);
        for(int i=1;i<v.size();i++)
            mc=max(mc,v[i]-v[i-1]);
        return ((long long)mr*mc)%mod;
        
    }
};