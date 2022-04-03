class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int i=0,j=0,k,l,m=ver1.size(),n=ver2.size();
        while(i<m&&j<n)
        {
            int s=0,t=0;
            while(i<m&&ver1[i]!='.')
            {
                    s*=10;
                    s+=(ver1[i]-'0');
                    i++;
            }
            while(j<n&&ver2[j]!='.')
            {
                    t*=10;
                    t+=(ver2[j]-'0');
                    j++;
            }
            // cout<<s<<" "<<t<<endl;
            if(s!=t)
                return s>t?1:-1;
            i++,j++;
        }
        int s=0,t=0;
            while(i<m)
            {
                if(ver1[i]!='.')
                {
                    s*=10;
                    s+=(ver1[i]-'0');
                }
                i++;
            }
            while(j<n)
            {
                // cout<<" "<<j<<endl;
                if(ver2[j]!='.')
                {
                    t*=10;
                    t+=(ver2[j]-'0');
                }
                j++;
            }
        // cout<<s<<" "<<t<<endl;
             if(s!=t)
                 return s?1:-1;
        return 0;
    }
};