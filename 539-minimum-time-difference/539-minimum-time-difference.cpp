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
        // 0000=>2400
        //,cmp);
        // for(int i=0;i<time.size();i++)
        // {
        //     if(time[i]>"12:00")
        //     {
        //         int x=10*(time[i][0]-'0')+(time[i][1]-'0')-12;
        //         time[i][0]='0'+x/10;
        //         time[i][1]='0'+x%10;
        //     }
        // }
        sort(time.begin(),time.end());
        int ans= convert(time.back())-convert(time[0]);
        // cout<<ans;
        ans=min(ans,1440-ans);
        for(int i=1;i<time.size();i++)
        {
             int a=convert(time[i])-convert(time[i-1]);
             ans=min(ans,min(a,1440-a));
        }
        // for(auto x:time)
        //     cout<<x<<" ";
        return ans;
    }
};