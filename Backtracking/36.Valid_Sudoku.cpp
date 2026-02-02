#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // -------- ROW CHECK --------
    bool checkrow(vector<vector<char>>& board, int k) {
        if (k == 9) return true;

        for (int i = 0; i < 9; i++) {
            if (board[k][i] == '.') continue;

            for (int j = i + 1; j < 9; j++) {
                if (board[k][j] == '.') continue;

                if (board[k][i] == board[k][j]) {
                    cout << "element " << board[k][i]
                         << " repeated in row " << k << endl;
                    return false;
                }
            }
        }
        return checkrow(board, k + 1);
    }

    // -------- COLUMN CHECK --------
    bool checkcol(vector<vector<char>>& board, int k) {
        if (k == 9) return true;

        for (int i = 0; i < 9; i++) {
            if (board[i][k] == '.') continue;

            for (int j = i + 1; j < 9; j++) {
                if (board[j][k] == '.') continue;

                if (board[i][k] == board[j][k]) {
                    cout << "element " << board[i][k]
                         << " repeated in col " << k << endl;
                    return false;
                }
            }
        }
        return checkcol(board, k + 1);
    }

    // -------- 3x3 BOX CHECK --------
    bool checkbox(vector<vector<char>>& board, int k) {
        if (k == 9) return true;

        bool seen[9] = {false};

        int rowStart = (k / 3) * 3;
        int colStart = (k % 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[rowStart + i][colStart + j];
                if (c == '.') continue;

                int idx = c - '1';
                if (seen[idx]) {
                    cout << "element " << c
                         << " repeated in box " << k << endl;
                    return false;
                }
                seen[idx] = true;
            }
        }
        return checkbox(board, k + 1);
    }

    // -------- FINAL CHECK --------
    bool isValidSudoku(vector<vector<char>>& board) {
        if (!checkrow(board, 0)) return false;
        if (!checkcol(board, 0)) return false;
        if (!checkbox(board, 0)) return false;
        return true;
    }
};
