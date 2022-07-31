class Solution {
public:
    int clumsy(int n) {
        if(n<=2) return n==2?2:1;
      int val=(n*(n-1))/(n-2)+n-3;
        n-=4;
        //apply 4 operations directly
        while(n>3)
        {
            val= val-((n*(n-1))/(n-2))+n-3;
            n-=4;
        }
        val-= (n==3?6:n==2?2:n==1?1:0);
        return val;
    }
};