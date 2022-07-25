class Solution {
    vector<int> ans;
    int diff;
public:
    void solve(int n,int num)
    {
        if(n==0)//fill this no
        {
            ans.push_back(num);
            return ;
        }
        //choose -diff or +diff
        int last=num%10;
        if(last-diff>=0)
            solve(n-1,num*10+(last-diff));
        if(last+diff<=9&&diff!=0)
            solve(n-1,num*10+(last+diff));
            
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        diff=k;
        for(int i=1;i<=9;i++)
            solve(n-1,i);
        return ans;
    }
};