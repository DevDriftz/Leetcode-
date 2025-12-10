#include<iostream>
#include<vector>
using namespace std ; 

class Solution {
public:

    void solve(vector<int>&nums,vector<vector<int>>&ans,int index){
        int n = nums.size();
        if(index==nums.size()){
            ans.push_back(nums);
            for(int i : nums){
                cout<<i<<" ";
            }
            cout<<endl;
            return ; 
        }

        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            solve(nums,ans,index+1);
            //backtracking step ==> imp 
            swap(nums[i],nums[index]);
        }
        
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ; 
        solve(nums,ans,0);
        return ans ; 

    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    Solution s1;
    s1.permute(nums);


}