class Solution {
public:
    int numberOfSteps(int n) {
        int count=0;
        while(n)
        {
            if(n&1)//odd
                n--;
            else
            n/=2;
            count++;
            // cout<<n<<" "<<count<<endl;
        }
        return count;
    }
};