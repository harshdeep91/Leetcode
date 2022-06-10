class Solution {
    unordered_map<string,vector<string>> m;
public:
    void dir(int &j,string path,string &t)
    {
        path.push_back('/');
        while(t[j]!='(')
        {
            path.push_back(t[j++]);
        }
        j++;
        string l; 
        while(t[j]!=')')
            l.push_back(t[j++]);
        j++;
        m[l].push_back(path);
        if(j<t.size()&&t[j]==' ')j++;
        // cout<<path<<" "<<l<<endl;
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        //find content
        m.clear();
        int i=0;
        while(i<paths.size())
        {
            int j=0;
            string path;    
            while(paths[i][j]!=' ')
                path.push_back(paths[i][j++]);
            j++;
            while(j<paths[i].size())
                dir(j,path,paths[i]);
            i++;
        }
        vector<vector<string>> ans;
        for(auto x:m)
            if(x.second.size()>1)
          ans.push_back(x.second);
        return ans;
    }
};