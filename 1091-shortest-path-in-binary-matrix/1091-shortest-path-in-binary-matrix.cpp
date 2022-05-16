class Solution {
public:
    int rows, cols;
    const vector<pair<int,int>> dirs{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int bfs(vector<vector<int>>& grid, int r, int c) {
        if (rows == 1) {
            return grid[0][0] ? -1 : 1;
        }
        queue<pair<int,int>> togo;
        int sz, dis = 0;
        togo.push({r, c});
        grid[r][c] = 1;
        while (!togo.empty()) {
            sz = togo.size();
            dis++;
            while (sz--) {
                auto cur = togo.front();
                togo.pop();
                for (auto &dir : dirs) {
                    auto row = cur.first + dir.first, col = cur.second + dir.second;
                    if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col]) {
                        continue;
                    }
                    togo.push({row, col});
                    grid[row][col] = 1;
                    if (row == 0 and col == 0)
                        return dis + 1;
                }
            }
        }
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        if (grid[0][0] || grid[rows - 1][cols - 1])
            return -1;
        return bfs(grid, rows - 1, cols - 1);
    }
};