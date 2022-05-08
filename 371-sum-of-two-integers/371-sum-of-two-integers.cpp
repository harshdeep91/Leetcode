class Solution {
public:
    int getSum(int a, int b) {
            int carry,ans,i=2;
        while(b)
        {
            
            int ans = a ^ b;   //01
            unsigned carry = a & b;//10
            carry <<= 1;      //100
            a = ans|carry;    //101
            b = carry&ans;
            // cout<<a<<" "<<b<<endl;
        }
        return a;
    }
};