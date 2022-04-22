class Solution {
public:
    int mySqrt(int x) {
        int l=1,h=x;
        while(l<=h)
        {
            long long int m=l+(h-l)/2;
            if(m*m==x)
                return m;
            if(m*m<x)
                l=m+1;
            else
                h=m-1;
        }
        return h;
    }
};