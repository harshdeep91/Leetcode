class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //graph coloring 0 1 2
        vector<int> color(graph.size(),-1);
       queue<int> q;
        for(int j=0;j<graph.size();j++)
        {
            if(color[j]==-1)
            {
                   q.push(j);
                color[j]=1;
                while(!q.empty())
                {
                    int i=q.front();
                    q.pop();
                    for(auto x:graph[i])
                    {
                        if(color[x]==-1)//not assigned till now
                        {
                            color[x]=!color[i];
                            q.push(x);
                        }
                        else if(color[x]==color[i])
                            return 0; 
                    }
                }
            }
            
        }
        
        
        return 1;
    }
};