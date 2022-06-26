class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int i=0,j=0,sum=0,mx=0,n=c.size()-k;
        while(i<c.size())sum+=c[i++];
        if(n==0)return sum;
        i=0;
        while(j<c.size())
        {
            sum-=c[j];
            if(j-i+1==n)
            {
                mx=max(sum,mx);
                sum+=c[i++];
            }
            j++;
        }
        return mx;
    }
};