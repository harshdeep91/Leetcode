class Solution {
public:
    string fractionAddition(string e) {
        //find num //find den //by using lcm find num
        
        int i=0,val,val2;
        long long den=1,num=0;
        while(i<e.size())
        {
            while(e[i++]!='/');
            den*=e[i++]-'0';
            if(i<e.size()&&e[i]=='0')
                den*=10,i++;
        }
        i=0;
        while(i<e.size())
        {
            val=1;
            if(e[i]=='-'||e[i]=='+') // for sign
                val=e[i++]=='-'?-1:1;
            val*=e[i++]-'0'; // for value
            if(i<e.size()&&e[i]=='0')//means 10
                val=val==-1?-10:10,i++;
            i++; // for /
            val2=e[i++]-'0'; //for denominator
            
            if(i<e.size()&&e[i]=='0')//means 10
                val2=10,i++;
            
            num+= val*(den/val2);
            // cout<<val<<" "<<val2<<" "<<num<<endl;
        }
        // cout<<num<<" "<<den<<endl;
        if(num==0)return "0/1";
        // divide extra value
        for(int i=min(abs(num),abs(den));i>0;i--)
            if(num%i==0&&den%i==0)
            {
                // cout<<i<<" ";
                num/=i;
                den/=i;
                break;
            }
        // cout<<num<<" "<<den<<endl;
        return to_string(num)+"/"+to_string(den);
    }
};