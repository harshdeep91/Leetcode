typedef pair<int,int> pp;
class Solution {
public:
    bool isNStraightHand(vector<int>& h, int g) {
        int n=h.size(),i=0,count=0;
        if(n%g)return 0;
        sort(h.begin(),h.end());
        priority_queue<pp,vector<pp>,greater<pp>> q;
        while(i<n&&count+q.size()<n/g)
        {
            //two options start new or include with prev
            if(!q.empty()&&q.top().second==g)
                q.pop(),count++;
            else if(!q.empty()&&q.top().first+1==h[i])
            {
                int size=q.top().second;
                q.pop();
                q.push({h[i++],size+1});
            }
            else
            q.push({h[i++],1});
        }
        // cout<<i<<" "<<count<<" "<<q.top().first<<" "<<q.top().second<<endl;
        while(!q.empty()&&i<n)
        {
            int val=q.top().first;
            int size=q.top().second;
            q.pop();
            if(size==g)count++;
            if(size!=g)
            {
                if(val+1==h[i])
                q.push({h[i++],size+1});
                else return 0;
            }
        }
        // cout<<count<<" ";
        while(!q.empty()&&q.top().second==g)q.pop(),count++;
        // cout<<count<<" ";
        return count==n/g;
    }
};