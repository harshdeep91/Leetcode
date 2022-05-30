class Solution {
public:
    string discountPrices(string s, int d) {
        int i=0;
        bool num=0;
        d=100-d;
        long long t,p,k;
        string ans;
        while(i<s.size())
        {
            num=0;
            t=0;
            string tmp;
            if(s[i]=='$')//that means dollar;
            {
                num=1;
                tmp.push_back(s[i++]);
            }
                while(i<s.size()&&s[i]!=' ')
            {
                if(s[i]<'0'||s[i]>'9')//not a number
                   num=0;
                    if(num)
                        t*=10,t+=(s[i]-'0');
                tmp.push_back(s[i++]);
                   
            }
            
            if(num&&(tmp.size()>1))
            {
                
                t*=d;
                 p=t/100;
                 k=t%100;
                string c="$";
                // if(p==0)
                //     c.push_back('0');
                //  if(p)
                     c+=to_string(p);
                c.push_back('.');
                if(k<=9)
                    c.push_back('0');
                c+=to_string(k);
                tmp=c;
            }
            tmp.push_back(' ');
            ans+=tmp;
            i++;
        }
        ans.pop_back();
        return ans;
    }
};