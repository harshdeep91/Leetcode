class Solution {
public:
    int lastRemaining(int n) {
        return lastRemaining(n, 0);
    }
    
    int lastRemaining(int n, int right) {
        if(n == 1)
            return 1;
        int pos = lastRemaining(n >> 1, right^1) << 1;
        return right && n % 2 == 0? pos-1: pos;
    }
};