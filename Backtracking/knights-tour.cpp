#include<iostream>
#include<vector>

using namespace std; 


class Solution{
public:

    int findTarget(int target, int n){
        if(target==n){
            return ;
        }

        
    }

    bool checkValidGrid(vector<vector<int>>& grid){
        bool ans = true; 
        findTarget(0,grid.size());

        return ans ; 
    }
};

int main(){

    vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    Solution s;
    cout<<s.checkValidGrid(grid);
    return 0;
}