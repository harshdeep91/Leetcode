class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[3]={-1,0,1},m=board.size(),n=board[0].size(),live;
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                live=0;
                for(int x=0;x<3;x++)
                {
                    for(int y=0;y<3;y++)
                    {
                        if((x==1&&y==1)||(i+dx[x]<0||i+dx[x]>=m||j+dx[y]<0||j+dx[y]>=n))
                            continue;
                        if(board[i+dx[x]][j+dx[y]]==1)
                        live++;
                    }
                }
                if(board[i][j]==1)//live
                {
                    if(live==2||live==3)
                        ans[i][j]=1;
                }
                else
                {
                    if(live==3)
                        ans[i][j]=1;
                }
                // cout<<live<<" "<<ans[i][j]<<endl;
            }
            // cout<<endl;
        }
        
        board=ans;
    }
};