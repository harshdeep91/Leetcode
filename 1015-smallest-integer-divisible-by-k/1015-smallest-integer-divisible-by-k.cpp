class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
          int n=0,carry=0,end=1e7;
        do
        {
            carry= (carry*10+1)%k;
            n++;
        }while(n<end&&carry);
        return n<end?n:-1;
    }
};