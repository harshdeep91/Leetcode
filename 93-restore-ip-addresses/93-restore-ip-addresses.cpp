class Solution {
public:
    bool check (string &s)
    {
        if(s.size()>3)
            return 0;
        else if(s.size()==3)
        {
             if(s[0]=='2')
            {
                if(s[1]=='5')
                {
                    if(s[2]<='5')
                        return 1;
                    else
                        return 0;
                }
                else if(s[1]<'5')
                    return 1;
                else
                    return 0;
           }
            else if(s[0]=='1')
                return 1;
            else
                return 0;
        }
       else if(s.size()==2)
       {
           if(s[0]=='0')
               return 0;
           return 1;
       }
        return 1;
    }
    void solve(int i,string back,string &s,int dots,vector<string> &v,string ans)
    {
    
        if(i==s.size())
        {
            if(!dots&&back.size())
            {
                    ans+=back;
                     v.push_back(ans);
            }
            return;
        }
        //cout<<s[i]<<endl;
            back+=s[i];
        // cout<<ans<<" "<<back<<endl;
            if(check(back))//place dot
            {
                solve(i+1,"",s,dots-1,v,(ans+back+"."));
                solve(i+1,back,s,dots,v,ans);
            }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        solve(0,"",s,3,v,"");
        return v;
    }
};