class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n+1,1);
        for(int i=2;i<=sqrt(n);i++)
        {
            if(v[i])
            {
                for(int j=2;i*j<=n;j++)
                {
                    v[j*i]=0;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++)
            if(v[i])
                count++;
                
//         for(auto x:v)
//         {
//             // cout<<x<<" ";
//             if(x==0)
//                 count++;
//         }
            
        return count;
    }
};