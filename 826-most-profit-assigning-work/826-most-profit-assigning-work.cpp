class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
          vector<pair<int,int>> v;
         for(int i=0;i<profit.size();i++)
         v.push_back({difficulty[i],profit[i]});
         sort(v.begin(),v.end());
         int mx=0,j=0,ans=0;
         sort(worker.begin(),worker.end());
         for(int i=0;i<worker.size();i++)
         {
             while(j<v.size()&&v[j].first<=worker[i])
             {
                 mx=max(v[j].second,mx);
                 j++;
             }
             ans+=mx;
         }
         return ans;
    }
};