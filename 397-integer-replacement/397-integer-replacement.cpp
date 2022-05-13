class Solution {
public:
    int integerReplacement(int n) {
         if(n==INT_MAX) return 32;
        int count  = 0;
        while(n>3){
            if(n%2==0){
                // if n is even
                n=n>>1;
            }else{
                // if n is odd
                int increment = n+1;
                int decrement = n-1;
                int unsetBits = 0;
                
                while(!(increment&1)){
                    unsetBits++;
                    increment = increment>>1;
                }
                while(!(decrement&1)){
                    unsetBits--;
                    decrement = decrement>>1;
                }
                if(unsetBits>0){
                    n = n+1;
                }else{
                    n = n-1;
                }
            }
            count++;
        }
        
        if(n<=3) count+=(n-1);
        
        return count;
    }
};