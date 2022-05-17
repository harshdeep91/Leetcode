class Solution {
    vector<vector<char>> mat;
    int count,m,n;
public:
    bool check(int i,int j)
    {
        if(i>=0&&i<m&&j>=0&&j<n&&mat[i][j]=='X')
        {
            mat[i][j]='L';
            return 1;
        }
        return 0;
    }
    void bfs(int &i,int &j)
    {
        // cout<<i<<" "<<j<<endl;
        queue<pair<int,int>> q;
        q.push({i,j});
        mat[i][j]='L';
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(check(r-1,c))q.push({r-1,c});
            if(check(r+1,c))q.push({r+1,c});
            if(check(r,c-1))q.push({r,c-1});
            if(check(r,c+1))q.push({r,c+1});
        }
        count++;
    }
    int countBattleships(vector<vector<char>>& board) {
        mat=board;
        count=0,m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(mat[i][j]=='X')
                bfs(i,j);    
        }
        return count;
    }
};