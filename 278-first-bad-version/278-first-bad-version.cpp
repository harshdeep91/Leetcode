// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       unsigned l=1,h=n,m;
        while(l<=h)
        {
            m=(l+h)>>1;
            if(isBadVersion(m))
                h=m-1;
            else
                l=m+1;
        }
        return l;
    }
};