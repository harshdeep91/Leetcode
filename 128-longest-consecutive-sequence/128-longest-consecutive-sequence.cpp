class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
      unordered_map<int,pair<int,int>> m; //first low,second high
      for(auto x:nums)
              m[x]={x,x}; 
      for(auto x:nums){
          //add low and high
          if(m.find(x-1)!=m.end())
          {
              m[x].first=min(m[x-1].first,m[x].first);
              m[x].second=max(m[x-1].second,m[x].second);
          }
          if(m.find(x+1)!=m.end())
          {
              m[x].first=min(m[x].first,m[x+1].first);
              m[x].second=max(m[x+1].second,m[x].second);
          }
      }
      int mx=0,flag=1;
      while(flag)
      {
          flag=0;
          for(auto x:nums){
          //add low and high
              m[x].first=min(m[m[x].first].first,m[x].first);
              m[x].second=max(m[m[x].second].second,m[x].second);
      }
          for(auto x:m)
          {
              if(x.second.second-x.second.first+1>mx)//means do it again
              {
                  mx=x.second.second-x.second.first+1;
                  flag=1;
              }
              // mx=max(,mx);
              // cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
          }
          
      }
      return mx;
  }
};