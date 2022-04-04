class Solution {
public:
    int trailingZeroes(int n) {
        int k=5,ans=0;;
        while(n/k)
        {
            ans+=n/k;
            k*=5;
        }
        return ans;
    }
};