class Solution {
public:
    int numberOfSteps(int n) {
        int count=0;
     
        while(n>1)
        {
            if(n&1)//odd
                n--,count++;
            // else
            n/=2;
            count++;
            // cout<<n<<" "<<count<<endl;
        }
        return n==1?count+1:count;
    }
};