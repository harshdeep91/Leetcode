class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> pos,neg;
        vector<int> ans;
        vector<bool> vis(a.size(),0);
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>0)
            {
                pos.push(i);
            }
            else
            {
                if(pos.empty())//dont push as they will never collide push them in ans
                    vis[i]=1;
                else
                    neg.push(i);
            }
            //now normalize
            //any one must be empty
            while(!pos.empty()&&!neg.empty())
            {
                if(a[pos.top()]>abs(a[neg.top()]))
                    neg.pop();
                else if(a[pos.top()]==abs(a[neg.top()]))
                    pos.pop(),neg.pop();
                else
                    pos.pop();
            }
            //if posempty push all negative
            while(!neg.empty())
            {
                vis[neg.top()]=1;
                neg.pop();
            }
        }
        while(!pos.empty())
            {
                vis[pos.top()]=1;
                pos.pop();
            }
        for(int i=0;i<a.size();i++)
            if(vis[i])ans.push_back(a[i]);
        return ans;
    }
};