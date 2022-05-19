class Solution {
    vector<int> a;
public:
    int maxyt()
    {
        int mx=0;
        for(int i=0;i<26;i++)
            mx=max(mx,a[i]);
        return mx;
    }
    int characterReplacement(string s, int k) {
        int i=0,j=0,mx=0,t,count=0,maxyt=0;
        a.resize(26,0);
        while(j<s.size())
        {
            a[s[j]-'A']++;
            maxyt=max(maxyt,a[s[j]-'A']);
            if(j-i+1-maxyt>k)
            {
                a[s[i++]-'A']--;
                // cout<<count++<<" ";
            }
            // cout<<endl;
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};