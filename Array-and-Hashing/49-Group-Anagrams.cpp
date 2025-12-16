#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    void solve(vector<pair<string,string>>& v,vector<vector<string>>& ans,int i){

        if(i >= v.size()) return;

        vector<string> baggu;
        baggu.push_back(v[i].second); // original string

        while(i + 1 < v.size() && v[i].first == v[i + 1].first){
            baggu.push_back(v[i + 1].second);
            i++;
        }

        ans.push_back(baggu);
        solve(v, ans, i + 1);
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> ans;
        vector<pair<string,string>> v;

        // store sorted + original
        for(auto s : strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            v.push_back({sorted, s});
        }

        // sort by sorted string
        sort(v.begin(), v.end());

        solve(v, ans, 0);
        return ans;
    }
};

int main(){
    Solution s1;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    auto res = s1.groupAnagrams(strs);

    for(auto &group : res){
        for(auto &word : group){
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
