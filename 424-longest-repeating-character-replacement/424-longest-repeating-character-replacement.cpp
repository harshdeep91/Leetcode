class Solution {
    vector<int> a;
public:
    int maxy()
    {
        int mx=0;
        for(int i=0;i<26;i++)
            mx=max(mx,a[i]);
        return mx;
    }
    int characterReplacement(string s, int k) {
        int i=0,j=0,mx=0,t;
        a.resize(26,0);
        while(j<s.size())
        {
            a[s[j]-'A']++;
            while(i<j&&j-i+1-maxy()>k)
            {
                a[s[i++]-'A']--;
            }
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};