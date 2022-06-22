/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    unordered_map<int,vector<int>> m;
public:
    int dfs(int i)
    {
        int val=m[i][0];
        for(int j=1;j<m[i].size();j++)
        {
            val+=dfs(m[i][j]);
        }
        // cout<<i+1<<" "<<val<<endl;
        return val;
    }
    // static bool cmp(Employee *a ,Employee *b)
    // {
    //     return a->id<b->id;
    // }
    int getImportance(vector<Employee*> e, int id) {
        //find the id first
        for(auto x:e)
        {
            m[x->id].push_back(x->importance);
            for(auto y:x->subordinates)
                m[x->id].push_back(y);
        }
        // vector<bool> vis(e.size()+1,0);
        // for(auto x:employees)
        
        return dfs(id);
    }
};