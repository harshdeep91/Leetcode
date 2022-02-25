// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
     bool check(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& vis)
    {
        if(r>=0&&c>=0&&r<grid.size()&&c<grid[0].size()&&grid[r][c]==0&&vis[r][c]==false)
        return 1;
        return 0;
    }
    vector<vector<int>>nearest(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(grid.size(),(vector<bool>(grid[0].size(),0)));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0;
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            
            int size=q.size();
            while(size--)
            {
                int r=q.front().first;
                int c=q.front().second;
                 q.pop();
                    if(check(r,c+1,grid,vis))//right
                {
                    vis[r][c+1]=1;
                    grid[r][c+1]=grid[r][c]+1;
                    q.push({r,c+1});
                }
                    if(check(r+1,c,grid,vis))//down
                {
                    vis[r+1][c]=1;
                    grid[r+1][c]=grid[r][c]+1;
                    q.push({r+1,c});
                }
                    if(check(r,c-1,grid,vis))//left
                {
                    vis[r][c-1]=1;
                    grid[r][c-1]=grid[r][c]+1;
                    q.push({r,c-1});
                }
                   if(check(r-1,c,grid,vis))//up
                {
                    vis[r-1][c]=1;
                    grid[r-1][c]=grid[r][c]+1;
                    q.push({r-1,c});
                }
            }
        }
        return grid;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends