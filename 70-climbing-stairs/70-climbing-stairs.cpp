class Solution {
public:
    int climbStairs(int n) {
        int prev=2,prevprev=1,curr;
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        for(int i=3;i<=n;i++)
        {
            curr=prev+prevprev;
            prevprev=prev;
            prev=curr;
        }
        return curr;
    }
};