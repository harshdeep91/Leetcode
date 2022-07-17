class Solution {
    int mod=1e9+7;
public:
    int kInversePairs(int n, int k) {
        //maintain prev array of size k 
        //after finding pattern from permutation
        // and making similarity with n and k we will arrive here check it by making dp of n,k and fill the values
        vector<int> prev(k+1,0),curr(k+1,0);
        for(int i=1;i<=n;i++)
        {
            prev[0]=1;//because of k==0 
            long long sum=0;
            int start=0;
            for(int j=0;j<=k;j++)
            {
                if(j-start+1>i)
                    sum=(sum-prev[start++]+mod)%mod;
                sum= (sum+prev[j])%mod;
                curr[j]=sum;
            }
            prev=curr;
        }
        return curr.back();
    }
};