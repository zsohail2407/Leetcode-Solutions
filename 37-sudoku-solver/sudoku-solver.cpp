class Solution {
private:
    bool checkvalid(vector<vector<char>>& board, int row, int col, char dt) {
        int r = (row / 3) * 3;
        int c = (col / 3) * 3;
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == dt)
            {
                return false;
            }
            if (board[i][col] == dt)
            {
                return false;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[r+i][c+j]==dt)
                {
                    return false;
                }
            }
        }
        return true;
    };
    

bool sol(vector<vector<char>>& board,int c)
{
    //bse
    if(c==81)
    {
    return true;
    }
    int col=c%9;
    int row=c/9;
    if(board[row][col]!='.')
    {
        return sol(board,c+1);
    }
    for(char a='1';a<='9';a++)
    {

        if(checkvalid(board,row,col,a))
        {
            board[row][col]=a;
            if(sol(board,c+1))
            {
                return true;
            }
            board[row][col]='.';
        }
    }
    return false;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        sol(board,0);
    }
};