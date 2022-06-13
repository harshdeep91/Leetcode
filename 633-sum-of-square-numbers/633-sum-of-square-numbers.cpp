class Solution {
public:
    bool judgeSquareSum(int c) {
       //a*a+b*b=c
        // a*a>=0
        //c-b*b>=0
        //b*b<=c
        //b<=sqrt(c)
        //means b must be less than sqrt of c
        // a=sqr(c-b) //check if it is integer or not
        // int b=sqrt(c);
        // cout<<b<<endl;
        for(int i=0;i<=sqrt(c);i++)
        {
            double a=sqrt(c-i*i);
            // cout<<a<<" ";
            if((int)a==a)
                return 1;
        }
       return 0;
    }
};