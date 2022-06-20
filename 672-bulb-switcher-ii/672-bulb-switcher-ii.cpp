//so we have this combination only 
            // they could be odd1 even1 odd2 even2
            //initially       1     1     1    1
            //so there can be 8 combination mx
            // presses=0 => 1,1,1,1
            // presses=1 => 4 choice => 0000 ,1010 ,0101, 1100
            //presses =2 => 0011,1001,0110 unique only
            //presses 3 => no different
 //odd
        //even
        //3k+1 => odd/2 ,even/2
        //odd1=odd-odd/2 odd2=odd/2;
        //even1=even-even/2 even2=even/2
class Solution {
public:
    int flipLights(int n, int p) {
        // int odd=n&1?n/2+1:n/2,even=n/2;
        // int odd1=odd-odd/2,odd2=odd/2;
        // int even1=even-even/2,even2=even/2;
        if(n==1)return p==0?1:2;
        if(n==2) return p==0?1:p==1?3:4;
         // if(n<4)//then directly put the ans
        return p==0?1:p==1?4:p==2?7:8;
    }
};
