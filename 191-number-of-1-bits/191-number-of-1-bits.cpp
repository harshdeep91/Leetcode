class Solution {
public:
    int hammingWeight(uint32_t N) {
       int count=0;
        while(N)
        {
            if(N&1)
            count++;
              N>>=1;
        }
        return count;
    }
};