#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    set<vector<int>> s;
    
    void solve(vector<int>&candidates,int target, int index, vector<int>&baggu, vector<vector<int>>&ans){
        
        if(target==0){
            if(s.find(baggu) == s.end()){
                ans.push_back(baggu);
                s.insert(baggu);
            }
            return;
        }
        
        if(target<0 || index==candidates.size()){
            return ; 
        }



        baggu.push_back(candidates[index]);
        solve(candidates,target-candidates[index] ,index+1,baggu,ans);
        baggu.pop_back(); // backtrack
        solve(candidates,target,index+1,baggu,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans ; 
        vector<int> baggu;
        solve(candidates,target,0,baggu,ans);

        for (auto &comb : ans) {
            for (int val : comb) {
                cout << val << " ";
            }
            cout << endl;
        }
        return ans;
    }
};

int main(){

    Solution s1;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    s1.combinationSum2(candidates,target);

}