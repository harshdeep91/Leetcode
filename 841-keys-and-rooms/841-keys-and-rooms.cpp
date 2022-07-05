class Solution {
    vector<bool> vis;
    int count=0;
public:
    void dfs(int i,vector<vector<int>>& rooms)
    {
        vis[i]=1;
        count++;
        for(auto x:rooms[i])
        {
            if(!vis[x])
                dfs(x,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size(),0);
        dfs(0,rooms);
        return count==rooms.size();
    }
};