class Solution {
public:
    int strStr(string haystack, string needle) {
        long long i=0,m=haystack.size(),n=needle.size(),mod=pow(10,15),Nsum=0,Hsum=0,j=0;
        long long p=1;
        while(i<n-1)
        {
            
            p=p*26%mod;
            i++;
        }
        // cout<<p<<endl;
        i=0;
       
       
        while(j<m)
        {
            if(j<n)
            {
                 Nsum=(((Nsum)*26)%mod+(needle[j]-'a'+1))%mod;
                 Hsum=(((Hsum)*26)%mod+(haystack[j]-'a'+1))%mod;
            }
            else
            {
                 Hsum=(Hsum-(haystack[i]-'a'+1)*p)%mod;
                 Hsum=(((Hsum)*26)%mod+(haystack[j]-'a'+1))%mod;
                 i++;
            }
            
             // cout<<haystack[j]<<" "<<Hsum<<" "<<Nsum<<endl;
            j++;
            if(j>=n&&Hsum==Nsum)
            {
                int c=0,k=i;
                while(c<n)
                {
                    if(needle[c]!=haystack[k])
                        break;
                    c++;
                    k++;
                }
                if(c==n)
                    return i;
            }
        }
        
        // cout<<i<<endl;
        return n?-1:0;
    }
};