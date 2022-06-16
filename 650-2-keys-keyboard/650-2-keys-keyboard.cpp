class Solution {
public:
    int minSteps(int n) {
        //find min factor multiply it with 2 check if divisible or not;
        int count=0,fac=1;
        if(n==1)return 0;
        // for(int i=2;i<=n;i++)            
        // {
        //     if(n%i==0)
        //     {
        //        fac=i;
        //        break; 
        //     }
        // }
        // //1 ,fac are the factors
        // count=fac;
        // cout<<fac<<" ";
        while(fac<n)
        {
            for(int i=2;i*fac<=n;i++)
            {
                if(n%(i*fac)==0)
                {
                    count+=i;
                    fac=i*fac;
                    // cout<<i<<" "<<fac<<" "<<count<<endl;
                    break;
                }
            }
        }
//         for(int i=fac*2;i<=n-1;i*=2)
//         {
//             if(n%i==0)
//             {
                
//                 count+=i/fac;
//                 fac=i;
//                 
//             }
//         }
//          if(fac!=n)
//            count+=n/fac;
        return count;
    }
};