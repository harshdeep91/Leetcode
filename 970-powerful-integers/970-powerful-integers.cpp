class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        long long val=0,ff=1,ss=1;
        for(int i=0;i<100;i++)
        {
            val=ff;
            ss=1;
            for(int j=0;j<100;j++)
            {
                val= ff+ss;
                if(val<=bound)
                    s.insert(val);
                else break;
                ss*=y;
            }
            if(ff>bound)break;
            ff*=x;
        }
        vector<int> ans;
        for(auto x:s)ans.push_back(x);
        return ans;
    }
};