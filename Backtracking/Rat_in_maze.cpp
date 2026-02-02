#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
  
    void solve(vector<vector<int>> &maze, int row, int col,
               string path, vector<string> &ans) {

        int n = maze.size();

   
        if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0)
            return;

        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

    
        maze[row][col] = 0;


        solve(maze, row + 1, col, path + "D", ans);
        solve(maze, row, col - 1, path + "L", ans);
        solve(maze, row, col + 1, path + "R", ans);
        solve(maze, row - 1, col, path + "U", ans);

        // backtrack
        maze[row][col] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        vector<string> ans;

        if (maze[0][0] == 0)  
            return ans;

        solve(maze, 0, 0, "", ans);

        for(auto &path: ans){
            cout<<path<<endl;
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>>maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    s.ratInMaze(maze);
    
    return 0;
}
