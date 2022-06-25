class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        vector<int> ans(t.size(),0);
        for(int i=t.size()-1;i>=0;i--)
        {
            while(!s.empty()&&t[s.top()]<=t[i])
                s.pop();
            if(!s.empty())
                ans[i]=s.top()-i;
            s.push(i);
        }
        return ans;
    }
};