class Solution {
public:
    int solve(int j,int i,vector<vector<int>>& triangle,vector<int> &v)
    {
        if(j==triangle.size())
         return 0;
        if(v[i]==INT_MAX)
        v[i]=solve(j+1,i,triangle,v);
            v[i+1]=solve(j+1,i+1,triangle,v);
        return min(v[i],v[i+1])+triangle[j][i];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> v(triangle.size()+1,INT_MAX);
        return solve(0,0,triangle,v);
    }
};