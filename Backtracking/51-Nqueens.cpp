#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:

    bool isSafe(vector<string>& board, int row, int col, int n){

        // column check (only previous rows)
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // upper-left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // upper-right diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void solve(vector<string>& board, vector<vector<string>>& ans, int row, int n){

        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(board, ans, row + 1, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(board, ans, 0, n);
        return ans;
    }
};


int main(){
     Solution s;
    int n = 4;

    vector<vector<string>> solutions = s.solveNQueens(n);

    int count = 1;
    for(auto &board : solutions){
        cout << "Solution " << count++ << ":\n";
        for(auto &row : board){
            cout << row << endl;
        }
        cout << endl;
    }

    cout << "Total solutions = " << solutions.size() << endl;
    return 0;
}