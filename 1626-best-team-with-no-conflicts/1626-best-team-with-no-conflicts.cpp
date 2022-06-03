class Solution {
public:
        int bestTeamScore(vector<int>& scores, vector<int>& ages) {
           int n = ages.size();
           vector<pair<int,int>>v;
           for(int i = 0;i<n;i++)
                v.push_back({ages[i],scores[i]});
           sort(v.begin(),v.end());
           int dp[n];
           int ans = INT_MIN;
           for(int i = 0;i<n;i++)
           {
               dp[i]=v[i].second;
               for(int j = i-1;j>=0;j--)
               {  
                   if(v[i].second>=v[j].second)
                   {
                       dp[i] = max(dp[i],dp[j]+v[i].second);
                   }
               }
               ans = max(ans,dp[i]);
           }
           return ans;
    }
};