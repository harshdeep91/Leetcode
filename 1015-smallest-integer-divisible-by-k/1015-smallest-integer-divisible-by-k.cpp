class Solution {
public:
    int smallestRepunitDivByK(int k) {
                if (k % 2 == 0 || k % 5 == 0) return -1;

          int n=0,carry=0,end=1e7;
        do
        {
            carry= (carry*10+1)%k;
            n++;
        }while(n<end&&carry);
        return n<end?n:-1;
    }
};