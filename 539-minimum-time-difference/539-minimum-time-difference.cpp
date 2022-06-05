class Solution {
public:
   int convert(string &s)
   {
       int a=10*(s[0]-'0')+(s[1]-'0');
       a*=60;
       a+= 10*(s[3]-'0')+(s[4]-'0');
       return a;
   }
    int findMinDifference(vector<string>& time) {
        sort(time.begin(),time.end());
        int ans= convert(time.back())-convert(time[0]);
        ans=min(ans,1440-ans);
        for(int i=1;i<time.size();i++)
        {
             int a=convert(time[i])-convert(time[i-1]);
             ans=min(ans,min(a,1440-a));
        }
        return ans;
    }
};