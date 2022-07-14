class Solution {
public:
    int minFlipsMonoIncr(string s) {
        //2 choice 2^n 
        //if i make any bit one then its all bits after it will be 1 also
        // 00110
        // at i th bit all 0 to i-1 must be 0 and i to n must be 1
        //so count the no of ones from left and count the no of zeroes from right
        int n=s.size();
        vector<int> lo(n,0),rz(n,0);
        for(int i=0;i<n;i++)
            lo[i]=(s[i]=='1')+(i-1>=0?lo[i-1]:0);
        
        for(int i=n-1;i>=0;i--)
            rz[i]=(s[i]=='0')+(i+1<n?rz[i+1]:0);
        
        // for(int i=0;i<n;i++)
        //     cout<<lo[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<rz[i]<<" ";
        //best position would be min of left+right
        int mi=lo[n-1];
        for(int i=0;i<n;i++)
            mi=min(mi,(i-1>=0?lo[i-1]:0)+rz[i]);
        return mi;
    }
};