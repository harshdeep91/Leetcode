class Solution {
public:
    int minDeletions(string s) {
        int a[26]={0};
        for(auto x:s)a[x-'a']++;
        vector<int> v;
        for(int i=0;i<26;i++)if(a[i])v.push_back(a[i]);
        sort(v.begin(),v.end());
        int count=0;
        for(int i=v.size()-2;i>=0;i--)
        {
            while(v[i]>0&&v[i]>=v[i+1])
            {
                v[i]--;
                count++;
            }
        }
        return count;
    }
};