class Solution {
public:
    
    bool canReach(string s, int minjump, int maxjump) {
        if(s[s.size()-1]=='1')
        return false;
        vector<int> dp(s.size(),0);
        dp[0]=0;
        int lastzero=1;
        // cout<<dp[0]<<" ";
        for(int j=1;j<s.size();j++)
        {
            if(s[j]=='0')
            {
                
                int l=max(0,j-maxjump);
                int h=j-minjump;
                // cout<<"--"<<l<<" "<<h<<endl;
                if(h>=0&&h-l+1>dp[h])
                   lastzero=0;    
            }
                dp[j]=lastzero++;
            // cout<<dp[j]<<" ";
                
        }
        //we need to find zero in range ok let me take distance of zero from the value
        return !dp[s.size()-1];
       
    }
};