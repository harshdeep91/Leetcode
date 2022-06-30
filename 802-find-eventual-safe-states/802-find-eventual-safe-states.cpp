class Solution {
    vector<int> vis,ans,already;
public:
    //if terminal it will return 1;
    bool dfs(int i,vector<vector<int>>& graph)
    {
        //0 for not visited
        //1 in processing 
        //2 for visited but not terminal
        //3 for visited but terminal
        // cout<<i<<" ";
        vis[i]=1;
        bool flag=1;
        for(auto x:graph[i])
        {
            if(vis[x]==0)
            {
                if(!dfs(x,graph))
                {
                    flag=0;
                    break;
                }
            }
            else if(vis[x]!=3)
            {
                    flag=0;
                    break;       
            }
                
        }
        if(flag&&vis[i]!=3)
        {
            ans.push_back(i);
            vis[i]=3;
        }
        else vis[i]=2;
        return flag;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // vector<int> ans;
        vis.resize(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            if(vis[i]==0)
            dfs(i,graph);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};