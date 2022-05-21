class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<long,int> m;
        int count=0;
        for(int i=0;i<points.size();i++)
        {
            m.clear();
            for(int j=0;j<points.size();j++)
            {
                if(i==j)continue;
                int x=abs(points[i][0]-points[j][0]);
                int y=abs(points[i][1]-points[j][1]);
                long dis=x*x+y*y;
                m[dis]++;
                if(m[dis]>1)//it means we got a new one
                    count+=m[dis]*2-2;
            }
        }
       return count;
    }
};