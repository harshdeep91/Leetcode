class Solution {
public:
    enum {a=0,e,i,o,u};
    int countVowelPermutation(int n) {
        //we can solve it by making last element extension
        //if we closely draw the figures we found out following 
        //relation that is we will make if we add this vowel at last
        if(n==1)return 5;
        vector<long long int> curr(5),prev={1,1,1,1,1};
        long long int sum=0,mod=1e9+7;
        //here 0 => a,similarly others
        // cout<<a<<" "<<e<<endl;
        while(--n)
        {
            curr[a]=(prev[e]+prev[i]+prev[u])%mod;
            curr[e]=(prev[a]+prev[i])%mod;
            curr[i]=(prev[e]+prev[o])%mod;
            curr[o]=(prev[i])%mod;
            curr[u]=(prev[o]+prev[i])%mod;
            prev=curr;
        }
        for(auto x:curr)
        {
            // cout<<x<<" "; 
            sum=(sum+x)%mod;
        }
        return sum;
    }
};