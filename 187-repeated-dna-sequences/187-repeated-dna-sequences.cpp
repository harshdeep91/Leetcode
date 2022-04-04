class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        int i=0,j=10;
        vector<string> v;
        while(j<=s.size())
        {
            string tmp=s.substr(i,j-i);
            mp[tmp]++;
            j++;
            i++;
        }
        for(auto x:mp)
        {
            if(x.second>1)
            v.push_back(x.first);
            // cout<<x.first.size()<<" ";
        }
        return v;
    }
};