class Solution {
    int a[10][2]={
        {4,6},//0
        {6,8},
        {7,9},
        {4,8},
        {0,3},//4 => {0,3,9}
        {10,10},//5 only one time
        {1,7},//6 => 0
        {2,6},
        {1,3},
        {2,4},
    },mod=1e9+7;
public:
    int knightDialer(int n) {
        n--;
        vector<long long> prev(11,1),now(11,0);
        prev[10]=0;
        while(n--)
        {
            for(int i=0;i<10;i++)
            {
                now[i]=0;
                for(auto x:a[i])
                {
                    now[i]=(now[i]+prev[x])%mod;
                }
                if(i==4)now[i]=(now[i]+prev[9])%mod;
                else if(i==6)now[i]=(now[i]+prev[0])%mod;
            }
            prev=now;
        }
        long long sum=0;
        for(auto x:prev)sum=(sum+x)%mod;
        return sum;
    }
};