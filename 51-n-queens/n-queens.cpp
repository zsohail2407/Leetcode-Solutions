class Solution {
    private:
    vector<vector<string>> output;
    vector<vector<int>> meracounter;
    int n;
    vector<string> board;

    void increase_decrease_counter(int r,int c,int mode)//mode may 1,-1 options
    {
       for (int i=1;i<n;i++)
       {
        if(r+i<n)
        {
            meracounter[r+i][c]+=mode;
        }
        if(r-i>=0)
        {
            meracounter[r-i][c]+=mode;
        }
        if(c+i<n)
        {
            meracounter[r][c+i]+=mode;
        }
        if(c-i>=0)
        {
            meracounter[r][c-i]+=mode;
        }
        if(c-i>=0 && r-i>=0)
        {
            meracounter[r-i][c-i]+=mode;
        }
        if(c+i<n && r-i>=0)
        {
            meracounter[r-i][c+i]+=mode;
        }
        if(c-i>=0 && r+i<n)
        {
            meracounter[r+i][c-i]+=mode;
        }
        if(c+i<n && r+i<n)
        {
            meracounter[r+i][c+i]+=mode;
        }
       }
    }

    
    void sol(int r)
    {
        //base case
        if(n==r)
        {
            output.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if (meracounter[r][i]==0)
            {
                meracounter[r][i]=-1;
                board[r][i]='Q';
                increase_decrease_counter(r,i,1);
                sol(r+1);
                increase_decrease_counter(r,i,-1);
                meracounter[r][i]=0;
                board[r][i]='.';

            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int s) {
        n=s;
        while(!output.empty())
        {
            output.pop_back();
        }
        meracounter.resize(n);
        board.resize(n);
        for(int i=0;i<n;i++)
        {
            meracounter[i].resize(n);
            for(int j=0;j<n;j++)
            {
                meracounter[i][j]=0;
            }
            board[i]=string(n,'.');
        }
        sol(0);
        return output;
    }
};