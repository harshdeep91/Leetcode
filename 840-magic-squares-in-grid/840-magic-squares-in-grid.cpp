class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        //count 9 square because constraint is small 
        int count=0;
        int r=grid.size()-2,c=grid[0].size()-2;
        int diffr[10]={0};
        // cout<<r<<" "<<c<<endl;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                // cout<<i<<" "<<j<<endl;
                int m=0,n=0,val=-1,sumr=0,sumc=0,diff=0,diffr[10]={0},v,t;
                //row
                while(m<3)
                {
                    n=0,sumr=0,sumc=0;
                    while(n<3)
                    {
                        v=grid[i+m][j+n];
                        sumr+=v;
                        sumc+=grid[i+n][j+m];
                        if(v>=1&&v<=9&&diffr[v]!=1)
                            diffr[v]=1;
                        else
                            m=4,n=4;
                        n++;
                    }
                    if(val==-1)val=sumr;
                    if(sumr!=val||sumr!=sumc)break;
                    m++;
                } 
                //diag
                
                if(m==3&&n==3)
                {
                    if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]==val&&grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]==val)
                    {
                        // cout<<i<<" "<<j<<" "<<val<<" "<<m<<" "<<n<<endl;    
                        count++;
                    }
                }
                
            }
        }
        return count;
    }
};


