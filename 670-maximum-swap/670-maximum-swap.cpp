class Solution {
public:
    int maximumSwap(int num) {
        //3 2 1 0 index
        //2 7 3 6 value  
        //find max value from right and its index
        // subtract and add by 10th multiplication
        int mx=num,count=0,index=0,value=0,k,tmp=num;
        while(num)
        {
            k=num%10;
            num/=10;
            if(k<value)//that means perform swapping
            {
                int place1 = pow(10,count);
                int place2 = pow(10,index);
                int t=tmp;
                t-= (k*place1+value*place2);
                t+= (value*place1+k*place2);  //second digit remove
                mx=max(t,mx);
            }
            else if(k>value)
            {
                index=count;
                value=k;
            }
            count++;
        }
        //first highest value is the mx number
        //find highest value from right to left swap it with lowest at front;
        //we can remove and add the number by 10 multiplication
        return mx;
    }
};