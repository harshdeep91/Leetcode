class Solution {
public:
    string countAndSay(int n) {
        string s="1",ans;
        int count,i;
        char put;
        
        while(--n)
        {
            for(int i=0;i<s.size();i++)
            {
                if(i==0)
                {
                    put=s[i];
                count=1;
                }
                else if(put==s[i])
                    count++;
                else
                {
                    ans+=to_string(count);
                    ans.push_back(put);
                       put=s[i];
                       count=1;
                }
            }
              ans+=to_string(count);
                    ans.push_back(put);
            s=ans;
            ans="";
        }
        return s;
    }
};