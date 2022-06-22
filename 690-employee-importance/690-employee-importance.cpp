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
            val+=dfs(m[i][j]);
        return val;
    }
    int getImportance(vector<Employee*> e, int id) {
        //find the id first
        for(auto x:e)
        {
            m[x->id].push_back(x->importance);
            for(auto y:x->subordinates)
                m[x->id].push_back(y);
        }
        return dfs(id);
    }
};