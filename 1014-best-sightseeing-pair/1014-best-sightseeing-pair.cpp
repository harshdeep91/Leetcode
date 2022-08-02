class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //maximum score will be find out when two max value used
        //maximum value is possible when left is max and right is also max
        vector<int> f,s;
        for(int i=0;i<values.size();i++)f.push_back(values[i]+i),s.push_back(values[i]-i);
        for(int i=1;i<values.size();i++)f[i]=max(f[i],f[i-1]);
        for(int i=s.size()-2;i>=0;i--)s[i]=max(s[i],s[i+1]);
        int mx=0;
        for(int i=0;i<values.size()-1;i++)
            mx=max(mx,f[i]+s[i+1]);
        return mx;
    }
};