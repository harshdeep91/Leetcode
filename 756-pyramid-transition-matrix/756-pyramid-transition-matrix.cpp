class Solution {
    unordered_map<string,vector<char>> m;
    unordered_map<string,bool> vis;
public:
    bool solve(int i,string top,string bottom)
    {
        
        if(bottom.size()==1)return 1;
        if(top.size()+1==bottom.size())//then increase level
            return solve(0,"",top);
        string key=top+bottom;
        if(vis.find(key)!=vis.end())return vis[key];
        //find first two digit and put the char one by one
        string prefix=bottom.substr(i,2);
        bool one=0;
        for(auto x:m[prefix])
        {
            top.push_back(x);
            if(solve(i+1,top,bottom))
                return 1;
            top.pop_back();
        }
        return vis[key]=0;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        //possible by recursion 
        //choose first two digits from bottom
        //find every three digit allowed 
        //check one by one
        //put the every possible triangle and check
        for(auto x:allowed)
        {
            m[x.substr(0,2)].push_back(x[2]);
        }
        return solve(0,"",bottom);
    }
};