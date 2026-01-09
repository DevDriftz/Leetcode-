#include <vector>
#include <iostream>
#include <set>
using namespace std;                                       

class Solution
{
public:
    set<vector<int>> s;
    void solve(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> &arr)
    {

        if (target < 0 || index == candidates.size())
        {
            return;
        }

        if (target == 0)
        {
            if (s.find(arr) == s.end())
            {
                ans.push_back({arr});
                s.insert(arr);
            }
        }

        arr.push_back(candidates[index]);

        solve(candidates, target - candidates[index], index + 1, ans, arr);
        solve(candidates, target - candidates[index], index, ans, arr);
        arr.pop_back();
        solve(candidates, target, index + 1, ans, arr);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(candidates, target, 0, ans, arr);
        return ans;
    }
};

int main()
{
    vector<int> candidates = {2, 3, 5};

    int target = 6;
    Solution s1;
    s1.combinationSum(candidates, target);
}