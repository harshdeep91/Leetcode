class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        
        int unit=num%10;
        int a=k;
        
        bool possible=0;
        int count=0;
        for(int i=0; i<10; i++)
        {
            
            count++;
            if(a==unit) {
                possible=1;
                break;
            }
            a+=k;
            a%=10;
        }
       cout<<possible;
        
        if(!possible) return -1;
        if(num<count*k) return -1;
        else 
            return count;
        
        
    }
};