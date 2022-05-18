class Solution {
    vector<vector<int>> ans;
    vector<int> low,dis;
    int time;
public:
    void tarzan(int i,vector<int> adj[],int parent)
    {
        low[i]=dis[i]=time++;
        for(auto x:adj[i])
        {
            if(dis[x]==-1)//not visited
            {
                tarzan(x,adj,i);
                if(low[x]<=low[i])//scc
                    low[i]=low[x];
                else if(dis[x]==low[x])//bridge
                    ans.push_back({i,x});
            }
            else if(x!=parent)//back edge
            {
                low[i]=min(low[i],low[x]);
            }
        }
        //how to detect answer now
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        ans.clear(),time=0,low.resize(n,-1),dis.resize(n,-1);
        vector<int> adj[n];
        for(auto x:con)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        tarzan(1,adj,-1);
        return ans;
    }
};