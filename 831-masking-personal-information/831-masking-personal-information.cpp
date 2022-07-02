class Solution {
public:
    
    string email(string &s)
    {
        //find first and last char 
        char first=s[0],last='0';
        int i=1;
        string d;
        d.push_back(first);
            while(i<s.size()&&s[i]!='@')
                last=s[i++];
        d+="*****";
        d.push_back(last);
        d+=s.substr(i);
        cout<<d<<" ";
        for(int i=0;i<d.size();i++)
        {
            if(d[i]>='A'&&d[i]<='Z')
                d[i]+=32;
        }
            //convert to lowercase
        
        return d;
    }
    string phone(string &s)
    {
        //find country code and last 4 digits
        string last;
        int count=-10;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                if(last.size()<4)
                last.push_back(s[i]);
                count++;
            }
        }
        reverse(last.begin(),last.end());
        switch(count)
        {
            case 0: return "***-***-"+last;
            case 1: return "+*-***-***-"+last;
            case 2: return "+**-***-***-"+last;
            case 3: return "+***-***-***-"+last;
        }
        return "";
    }
    string maskPII(string s) {
        //if phone it should have digit
        for(auto x:s)
            if(x<='9'&&x>='0')return phone(s);
        return email(s);
    }
};