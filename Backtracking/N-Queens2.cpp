#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
  void print(vector<vector<char>>& board){
    for(auto &row : board){
      for(auto &col : row){
        cout << col << " ";
      }
      cout << endl;
    }
  }
  
  bool issafe(vector<vector<char>>& board, int row, int col, int n) {

    for(int i = 0; i < col; i++)
        if(board[row][i] == 'Q')
            return false;

    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j] == 'Q')
            return false;

    for(int i=row, j=col; i<n && j>=0; i++, j--)
        if(board[i][j] == 'Q')
            return false;

    return true;
  } 

  void recurse(vector<vector<char>>& board, int col, int &ans){
    int n = board.size();

    if(col == n){
      ans++;          
      return; 
    }

    for(int row = 0; row < n; row++){
      if(issafe(board, row, col, n)){
        board[row][col] = 'Q';
        recurse(board, col+1, ans);
        board[row][col] = '.';   // backtrack
      }
    }
  }

  int totalNQueens(int n){
    vector<vector<char>> board(n, vector<char>(n,'.'));

    int ans = 0;
    recurse(board, 0, ans);

    return ans;
  }
};

int main() {
  Solution s1; 
  cout << "total soultions possible : " << s1.totalNQueens(8)<<endl;  
  return 0;
}
