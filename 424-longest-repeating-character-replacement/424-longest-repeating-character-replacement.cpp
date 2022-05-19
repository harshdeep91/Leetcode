class Solution {
public:
    bool check(string &s,int &k,int &m)
    {
        int i=0,j=0,a[26]={0},mx=0;
        while(j<s.size())
        {
            a[s[j]-'A']++;
            if(j-i+1==m)
            {
                mx=0;
                for(int t=0;t<26;t++)
                    mx=max(mx,a[t]);
                if(m-mx<=k)
                return true;
                a[s[i++]-'A']--;
            }
            j++;
        }
        return false;
    }
    int characterReplacement(string s, int k) {
        int l=k,h=s.size(),m;
        while(l<=h)
        {
            m=(l+h)>>1;
            //check substring
            if(check(s,k,m))
                l=m+1;
            else
                h=m-1;
        }
        return h>0?h:1;
    }
};