class Solution {
public:
    string ip6(string &s){
        //0 to 9
        //a to f
        //A to F
        int len=0,i=0,count;
        while(i<s.size())
        {
            count=0;
            while(i<s.size()&&s[i]!=':')
            {
                if(count<4&&((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')||(s[i]>='A'&&s[i]<='F')))
                    i++,count++;
                else
                    return "Neither";
            }
            if(count==0||count>4)return "Neither";
            i++;
            len++;
        }
        return len==8?"IPv6":"Neither";
    }
       string ip4(string &s){
        //0 to 255
         //no leading zeroes
        int len=0,i=0,count,val;
        while(i<s.size())
        {
            count=0;
            val=0;
            while(i<s.size()&&s[i]!='.')
            {
                
                if((s[i]<'0'||s[i]>'9')||(count==1&&val==0)||val>255)return "Neither";
                val*=10;
                val+=(s[i++]-'0');
                count++;
            }
            if(count==0||val<0||val>255) return "Neither";
            i++;
            len++;
        }
        return len==4?"IPv4":"Neither";
    }
    
    string validIPAddress(string s) {
        //for ip6
        //length must be 1<= len<=4
        //single scope
        //no .
        //total length must be 8
        //ip4
        //no leading zeroes 
        //no scope
        //1<=val<=255
        //total length =6
        if(s.back()==':'||s.back()=='.')return "Neither";
        for(int i=0;i<s.size();i++)
            if(s[i]==':') return ip6(s);
            else if(s[i]=='.') return ip4(s);
        return "Neither";
    }
};