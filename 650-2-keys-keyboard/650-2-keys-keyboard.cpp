class Solution {
public:
    int minSteps(int n) {
        //find min factor multiply it with 2 or 3 check if divisible or not;
        
        int count=0,fac=1;
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
        return count;
    }
};