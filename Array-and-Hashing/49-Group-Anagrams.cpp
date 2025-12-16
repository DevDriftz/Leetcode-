#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:

    void solve(vector<string>& strs, vector<vector<string>>& ans, int i){
        // base case
        if(i >= strs.size()) return;

        vector<string> baggu;
        baggu.push_back(strs[i]);

        // group all equal adjacent strings
        while(i + 1 < strs.size() && strs[i] == strs[i + 1]){
            baggu.push_back(strs[i + 1]);
            i++;
        }

        ans.push_back(baggu);

        // move to next new group
        solve(strs, ans, i + 1);
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> ans;

        // sort characters inside each string
        for(int i = 0; i < strs.size(); i++){
            sort(strs[i].begin(), strs[i].end());
        }

        // sort the whole array
        sort(strs.begin(), strs.end());

        // recursive grouping
        solve(strs, ans, 0);

        return ans;
    }
};

int main(){
    Solution s1;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> res = s1.groupAnagrams(strs);

    for(auto &group : res){
        for(auto &word : group){
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
