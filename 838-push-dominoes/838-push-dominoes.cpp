class Solution {
public:
    string pushDominoes(string d) {
        //now what to do
        queue<pair<char,int>> q;
        for(int i=0;i<d.size();i++)
            if(d[i]!='.')q.push({d[i],i});
        
        //last updated
        while(!q.empty())
        {
            int size=q.size(),last=-2;
            while(size--)
            {
                char dir=q.front().first;
                int nxt=(dir=='L')?q.front().second-1:q.front().second+1;
                q.pop();
                if(last==nxt&&dir!=d[nxt])//then update to .
                    d[nxt]='.';
                else if(nxt>=0&&nxt<d.size()&&d[nxt]=='.')//then only we will update
                {
                    d[nxt]=dir;
                    q.push({dir,nxt});
                    last=nxt;
                }
                
                // cout<<last<<" "<<nxt<<" "<<d<<endl;
            }
        }
        return d;
    }
};