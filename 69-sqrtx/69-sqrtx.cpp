class Solution {
public:
    int mySqrt(int x) {
        int l=1,h=min(x,46340);
        while(l<=h)
        {
            int m=(l+h)/2;
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