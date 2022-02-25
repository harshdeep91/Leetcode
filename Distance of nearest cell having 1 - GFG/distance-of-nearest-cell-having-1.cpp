// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
   
    void solve(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& vis,queue<pair<int,int>> &q)
    {
        if(r>=0&&c>=0&&r<grid.size()&&c<grid[0].size()&&grid[r][c]==0&&vis[r][c]==false)
           {
                    vis[r][c]=1;
                    grid[r][c]=grid[q.front().first][q.front().second]+1;
                    q.push({r,c});
           }
    }
    vector<vector<int>>nearest(vector<vector<int>>& grid) {
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
                 solve(r,c+1,grid,vis,q);
                 solve(r+1,c,grid,vis,q);
                 solve(r,c-1,grid,vis,q);
                 solve(r-1,c,grid,vis,q);   
                 q.pop();
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