#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
  
  bool issafe(vector<vector<char>>&board, char num, int row, int col){
    
    // checking col and rows 
    for(int i=0;i<9;i++){
      if(board[row][i]==num || board[i][col]==num){
        return false;
      }
    }

    //for checking 3x3 boxes....
      int startRow = (row/3)*3;
      int startCol = (col/3)*3;

      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(board[startRow+i][startCol+j] == num){
            return false;
          }
        }
      }

    return true;


  }

  bool helper(vector<vector<char>>&board, int row, int col){
    
    if(row==9){
      return true;
    }

    if(col == 9){
      return helper(board,row+1,0);
    }

    if(board[row][col] != '.'){
      return helper(board,row,col+1);
    
    }

    if(board[row][col] == '.'){
      //do something
      for(char i='1'; i<='9'; i++){
        if(issafe(board,i,row,col)){
          board[row][col]=i;
          if(helper(board,row,col+1)){
            return true;
          }
          board[row][col] = '.';
        }
      }
      
    }
    return false;
  }

  void solveSudoku(vector<vector<char>>&board){
    helper(board,0,0);
  }

};
