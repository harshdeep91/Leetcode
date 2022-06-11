class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        bool a[256][256]={0};
        for(auto x:mappings)
            a[x[0]][x[1]]=1;
        for(int i=0;i<=s.size()-sub.size();i++)
        {
            string p=s.substr(i,sub.size());
            int j=0;
            while(j<sub.size()&&p[j]==sub[j]||a[sub[j]][p[j]])j++;;
            if(j==sub.size())return true;
        }
        return false;
    }
};