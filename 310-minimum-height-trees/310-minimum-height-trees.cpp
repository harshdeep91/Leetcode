class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<unordered_set<int>> g(n);
        for(int i=0; i<edges.size(); i++){
            g[edges[i][0]].insert(edges[i][1]);
            g[edges[i][1]].insert(edges[i][0]);
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(g[i].size()==1){
                q.push(i);
            }
        }
        while(n>2){
            int s=q.size();
            n=n-s;
            while(s--){
                int j=q.front(); q.pop();
                int i=*g[j].begin();
                g[i].erase(j);
                if(g[i].size()==1)
                    q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
        
    }
};