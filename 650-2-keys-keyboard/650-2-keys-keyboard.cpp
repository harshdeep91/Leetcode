class Solution {
public:
    int minSteps(int n) {
        //find min factor multiply it with 2 or 3 check if divisible or not;
        //for 24 we can get less amount of value only if we continue in factors
        //because this will help to use full copy (means doubling of numbers)
        //so 24=>[1,2,3,4,6,8,12,24]=>[1,2,4,8,24]=> this pattern gives less answer
        
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