class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(pow(2,k)-1>s.size())return 0;
         unsigned p=1,t=k,j=0;
            // long long sum=pow(2,k)-1;
            //  sum=(sum*(sum+1))/2;  
        
            while(--t)//mask making
            {
                p<<=1;
                p|=1;
            }
        vector<bool> a(p+1,0);
        // cout<<sum<<" "<<t<<" "<<p<<endl;
         while(j<s.size())
         {
             
             t|=((s[j]-'0')&1);
             if(++j>=k)
             {
                 a[t]=1;  
                 // cout<<t<<" ";
                 t<<=1;
                 t&=p;
             }else
             t<<=1;
         }
        j=-1;
        while(++j<=p&&a[j]==1);
        // while(++j<=p)
        //     cout<<a[j]<<" ";
        // cout<<j<<" "<<p<<endl;
        return j>p;
    }
};