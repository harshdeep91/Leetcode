// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool check(int r,int c,vector<vector<int>>& grid)
    {
        if(r>=0&&c>=0&&r<grid.size()&&c<grid[0].size()&&grid[r][c]==1)
        return 1;
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                q.push({i,j});
            }
        }
        int count=0;
        while(!q.empty())
        {
            
            int size=q.size();
            while(size--)
            {
                int r=q.front().first;
                int c=q.front().second;
            q.pop();
                    if(check(r,c+1,grid))//right
                {
                    grid[r][c+1]=2;
                    q.push({r,c+1});
                }
                    if(check(r+1,c,grid))//down
                {
                    grid[r+1][c]=2;
                    q.push({r+1,c});
                }
                    if(check(r,c-1,grid))//left
                {
                    grid[r][c-1]=2;
                    q.push({r,c-1});
                }
                   if(check(r-1,c,grid))//up
                {
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                }
            }
            if(q.size())
            count++;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends