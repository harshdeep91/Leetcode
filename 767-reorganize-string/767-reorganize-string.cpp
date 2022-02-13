typedef pair<int,char> pp ;
class Solution {
public:
    string reorganizeString(string s) {
        int a[256]={0};
        for(int i=0;i<s.size();i++)
            a[s[i]]++;
        priority_queue<pp> q;
        for(int i=0;i<256;i++)
        {
             if(a[i]>0)
             {
                 q.push({a[i],i});
             }
        }
        string ans;
        while(q.size()>1)
        {
            pp f=q.top();
            q.pop();
            pp s=q.top();
            q.pop();
            // cout<<f.second<<" "<<s.second<<endl;
            ans.push_back(f.second);
            ans.push_back(s.second);
            if(f.first-1>0)
                q.push({f.first-1,f.second});
            if(s.first-1>0)
                q.push({s.first-1,s.second});
        }
        if(q.size()==1)
        {
            ans.push_back({q.top().second});
            return q.top().first==1?ans:"";
        }
        else
            return ans;
        
    }
};