class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int sum=0,prev=0,mi=wall.size();
            for(int j=0;j<wall[0].size();j++)
                sum+=wall[0][j];
        unordered_map<int,int> m;
        for(int i=0;i<wall.size();i++)
        {
            prev=0;
            for(int j=0;j<wall[i].size();j++)
            {
                prev+=wall[i][j];
                if(m.find(prev)==m.end())
                    m[prev]=wall.size();
                 m[prev]--;
                if(prev!=sum)
                mi=min(m[prev],mi);    
            }
            // if(sum=)
        }
//         for(int i=1;i<a.size()-1;i++)
//         {
//             cout<<a[i]<<" ";
            
//         }
        return mi;
    }
};