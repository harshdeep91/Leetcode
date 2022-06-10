class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int i=0,j=0,count=0,ans=0;
        bool a[256]={0};
    while(j<s.size())
    {
        
        while(a[s[j]])
                a[s[i++]]=0;
        ans=max(j-i+1,ans);
        a[s[j++]]=1;
    }
    return ans;
    }
};