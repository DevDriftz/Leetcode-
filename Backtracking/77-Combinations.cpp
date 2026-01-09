#include<iostream>
#include<vector>

using namespace std ; 


class Solution{

private:
    void solve(int st , int n, int k , vector<vector<int>>&ans, vector<int>&temp){
        if(k==0){
            ans.push_back(temp);
            return ; 
        }

        if (st > n) return;

        // pruning: if remaining numbers < k, can't pick enough
        if (n - st + 1 < k) return;
        temp.push_back(st);
        solve(st+1,n,k-1,ans,temp);
        temp.pop_back();
        solve(st+1,n,k,ans,temp);
    }


public:
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> ans ; 
        vector<int>temp;
        solve(1,n,k,ans,temp);


        for(auto &comb : ans){
            for(auto val : comb){
                cout<<val<<" ";
            }
            cout<<endl;
        }

        return ans;


    }



};

int main(){
    Solution s1;
    s1.combine(4,3);
}