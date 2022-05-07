class Solution {
public:
    int numDecodings(string s) {
        int n=s.size(),prevprev=0,prev=1,curr=0;
        if(s[0]=='0') return 0;
            for(int i=1;i<n;i++)
            {
                if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<'7'))
                {
                    curr=i==1?1:prevprev;
                }
                if(s[i]!='0')
                    curr+=prev;
                prevprev=prev;
                prev=curr;
                curr=0;
                // cout<<dp[i]<<" ";
            }
        return prev;
    }
};