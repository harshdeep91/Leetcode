class Solution {
    vector<int> ans;
public:
    void solve(int val,int n,int &k)
    {
        if(n==0)
        {
            ans.push_back(val);
                return ;
        }
        //we can either insert last-k or last +k
        int last=val%10;
        val*=10;
        if(k&&last-k<=9&&last-k>=0)
            solve(val+last-k,n-1,k);
        if(abs(last+k)<=9&&abs(last+k)>=0)
            solve(val+abs(last+k),n-1,k);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++)
            solve(i,n-1,k);
        return ans;
    }
};