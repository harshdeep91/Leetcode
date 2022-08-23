class Solution {
public:
    bool isPowerOfFour(int num) {
    //power of four is directly related to bits manipulation
      // 16 and 15 will give 0 but in 3 2 11&10=>1 ,
        //to separate power of 2 from power of 4 in power of 4 leftmost bit is at position odd
        // n= n&(n-1);
        // cout<<n;
        	return num > 0 && (num & (num - 1)) == 0 && (num & 0xAAAAAAAA) == 0;

        // return !n;
    }
};