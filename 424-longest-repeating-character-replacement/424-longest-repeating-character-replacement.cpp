class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,mx=0,maxyt=0,a[26]={0};
        while(j<s.size())
        {
            a[s[j]-'A']++;
            maxyt=max(maxyt,a[s[j]-'A']);
            if(j-i+1-maxyt>k)
                a[s[i++]-'A']--;
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};