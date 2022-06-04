class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      unordered_map<int,int> m;
        int count=0;
        for(auto x:nums)
            m[x]++;
        for(auto x:m)
            if(k==0)
                count+=(m[k+x.first]>1);
            else if(m.find(x.first+k)!=m.end())
            {
                // cout<<x.first<<" "<<x.first+k<<endl;
                count++;
            }
        
        return count;
    }
};