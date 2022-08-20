class Solution {
public:
    int minRefuelStops(int t, int f, vector<vector<int>>& s) {
        priority_queue<int> q;
        int count=0;
        for(int i=0;i<s.size()&&f<t;i++)
        {
            if(s[i][0]<=f)
                q.push(s[i][1]);
            else
            {
                count++;
                if(q.empty())return -1;
                f+= q.top();
                q.pop();
                // cout<<count<<" "<<f<<" "<<endl;
                i--;
            }
        }
        while(!q.empty()&&f<t)
        {
            count++;
            f+= q.top();
            q.pop();
        }
        return f>=t?count:-1;
    }
};