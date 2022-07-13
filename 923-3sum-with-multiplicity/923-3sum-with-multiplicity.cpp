class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        map<int,int> mp;
        for(auto x:arr)mp[x]++;
        vector<pair<int,int>> v;
        for(auto x:mp)v.push_back({x.first,x.second});
        long long count=0,mod=1e9+7,m,n,o;
        for(int i=0;i<v.size();i++)
        {
            //edge case 
            //if tuple is from same single element then ans is nc3
            m=v[i].second;
            if(3*v[i].first==target)
            {
                count = (count+ (m*(m-1)*(m-2))/6)%mod;
            }
            
            
   
            for(int j=i+1;j<v.size();j++)
            {
                n=v[j].second;
                o=target-v[i].first-v[j].first;
                //if tuple is from single+ same double
                // cout<<i<<" "<<j<<" "<<v[i].second<<" "<<v[j].second<<" "<<sum<<endl;
                if(o==v[i].first)
                {
                    count = (count+ n*((m*(m-1))/2))%mod;
                }
                else if(o==v[j].first) 
                {
                    count = (count+ m*((n*(n-1))/2))%mod;
                }
                else if(o>v[j].first&&mp[o])         //if tuple three diff
                {
                    count = (count+ m*n*mp[o])%mod;
                }
            }
        }
        return count;
    }
};