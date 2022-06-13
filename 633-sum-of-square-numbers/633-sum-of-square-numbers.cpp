class Solution {
    public:
    bool judgeSquareSum(int c) {
        if (c < 0) {
            return false;
        }
        long long left = 0, right = (int)sqrt(c);
        while (left <= right) {
            long long cur = left * left + right * right;
            if (cur < c) {
                left++;
            } else if (cur > c) {
                right--;
            } else {
                return true;
            }
        }
        return false;
    }
};