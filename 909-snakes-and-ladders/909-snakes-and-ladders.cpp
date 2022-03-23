///convert pos to i,j
            //pos=1 i=n-1,j=0;
            //pos=2 i=n-1 ,j=1;
            //pos=7 i=n-2 ,j=n-1 //reverse order if()
            //i=pos/n -1 if(pos%n==0) else without -1
            //j=n-pos%n if i==odd if(pos%n==0) -1
            //j=pos%n-1 if i==even
class Solution {
public:
    bool check(int &i,int &j,vector<vector<int>>& board)
    {
        if(i>=0&&i<board.size()&&j>=0&&j<board.size()&&board[i][j]!=-2)
            return true;
        return false;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        // for(int i=0;i<board.size();i++)
        // {
        //     for(int j=0;j<board.size();j++)
        //         cout<<board[i][j]<<" ";
        //     cout<<endl;
        // }
        queue<int> q;
        int n=board.size(),i,j,count=0,npos,pos,k;
        q.push(1);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int npos=q.front();
                 q.pop();
                if(npos==n*n)
                    return count;
            // cout<<npos<<" "<<count<<endl;
            for(int diff=1;diff<=6;diff++)
            { 
                pos=npos+diff;
                i=(pos%n)?n-1-pos/n:n-pos/n;
                k=n-i-1;
                j=(pos%n)?(k&1?n-pos%n:pos%n-1):(k&1?0:n-1);
                if(check(i,j,board))
                {
                    if(board[i][j]==-1)
                     q.push(pos);
                    else
                    q.push(board[i][j]);
                    
                        // cout<<board[i][j]<<" : "<<pos<<" * "<<i<<" "<<j<<endl;
                    board[i][j]=-2;//vis    
                }
            }
        }
            count++;
    }
        return -1;
    }
};