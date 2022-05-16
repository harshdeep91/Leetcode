class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int diff[3]={-1,0,1},r,c,R,C,count=1,n=size(grid);
        queue<pair<int,int>> q;
        if(grid[0][0]==1)return -1;
        q.push({0,0});
        grid[0][0]=2;
        if(n==1)return 1;
        while(!q.empty())
        {
            int size=q.size();
            count++;
            while(size--)
            {
                r=q.front().first ,c=q.front().second;
                q.pop();
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        R=r+diff[i],C=c+diff[j];
                        if(R<0||R>=n||C<0||C>=n||grid[R][C]>=1)continue;
                        if(R==n-1&&C==n-1)return count;
                        grid[R][C]=2;
                        q.push({R,C});
                        cout<<R<<" "<<C<<endl;
                    }
                }
            }
        }
        return -1;
    }
};