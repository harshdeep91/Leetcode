class Solution {
public:
      
    int countBattleships(vector<vector<char>>& board)
    {
        if(board.empty() || board.front().empty()) return 0;

        short rowCount = board.size();
        short colCount = board.front().size();

        int count{0};
        for(short y = 0; y < rowCount; ++y) {
            for(short x = 0; x < colCount; ++x) {
                if(board[y][x] == 'X') {
                    if(y > 0 && board[y - 1][x] == 'X') continue;
                    if(x > 0 && board[y][x - 1] == 'X') continue;
                    ++count;
                }
            }
        }
        return count;
    }
};