#include <iostream>
#include <vector>

using namespace std;

class Solution
{

private:
    bool issafe(vector<string> &board, int row, int col, int n)
    {

        // uper right board[row-2][col-1]
        if (row - 2 >= 0 && col - 1 >= 0 && board[row - 2][col - 1] == 'K')
        {
            return false;
        }
        if (row - 1 >= 0 && col - 2 >= 0 && board[row - 1][col - 2] == 'K')
        {
            return false;
        }

        // uper left board[row-2][col+1]
        if (row - 2 >= 0 && col + 1 < n && board[row - 2][col + 1] == 'K')
        {
            return false;
        }

        if (row - 1 >= 0 && col + 2 < n && board[row - 1][col + 2] == 'K')
        {
            return false;
        }

        return true;
    }
    void solve(vector<string> &board, vector<vector<string>> &ans, int row, int n)
    {

        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (issafe(board, row, col, n))
            {
                board[row][col] = 'K';
                solve(board, ans, row+1 , n);
                
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> NKnights(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(board, ans, 0, n);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> result = s.NKnights(4);

    int count =0; 
    for(auto &board : result){
        for(auto &row : board){
            cout<<row<<endl;
        }
        count++;
        cout<<"----"<<endl;
    }
    cout<<"Total possible solutions are = "<<result.size();
}