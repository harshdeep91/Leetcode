class Solution {
public:
    int convert(int &i, string &s)
    {
        int a=0,neg=1;
        if(s[i]=='-')
            i++,neg=-1;
        while(i<s.size()&&(s[i]!='+'&&s[i]!='i'))
            {
                a*=10;
                a+=s[i++]-'0';
            }
           a*=neg;
        // cout<<a<<" ";
        return a;
    }
    string complexNumberMultiply(string num1, string num2) {
        //(a+bi)*(c+di)=(ac-bd)+(ad+bc)i
        int a=0,b=0,c=0,d=0,i=0;
         a=convert(i,num1);
         i++;//+
         b=convert(i,num1);
         i=0;
         c=convert(i,num2);
         i++;
         d=convert(i,num2);
        
         return to_string(a*c-b*d)+"+"+to_string(a*d+b*c)+"i";
        
    }
};