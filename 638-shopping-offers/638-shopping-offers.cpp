class Solution {
    int ans;
    vector<int> p,need;
    vector<vector<int>> sp;
public:
    bool check(int &i)
    {
        for(int j=0;j<need.size();j++)
        {
            if(need[j]-sp[i][j]<0)
                return false;
        }
        return true;
    }
    void solve(int i,int count){
        
        if(i==sp.size())
        {
            for(int j=0;j<need.size();j++)
            {
                count+= need[j]*p[j];
            }
            ans=min(count,ans);
            return ;
        }
        //choose //decrease the needs/ increas the count
        int tmp=0;
        if(check(i))//if possible
        {
            int j=-1;
            while(++j<need.size())
                need[j]-=sp[i][j];
            solve(i,count+sp[i][j]);
                j=-1;
                while(++j<need.size())
                need[j]+=sp[i][j];
        }
        //not choose
        solve(i+1,count);
        // //choose directly
        // for(int j=0;j<need.size();j++)
        //     need
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int count=0;
        p=price,need=needs,sp=special;
        for(int i=0;i<price.size();i++)
            count+=(price[i]*needs[i]);
        ans=count;
        solve(0,0);
            return ans;
    }
};