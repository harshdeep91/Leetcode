class Solution {
public:
    int divide(int dividend, int divisor) {
        
           int a=abs(dividend);
        int b=abs(divisor);
        if(divisor==-1&&dividend==INT_MIN)return INT_MAX;
        if(b==1)return dividend*divisor;
        long long int sum=0;
        int i=0;
        while(sum<=a){
            sum=sum+b;
            i++;
        }
        if((long long int)divisor*dividend<0)
        return -(i-1);
        else
        return i-1;
    }
};