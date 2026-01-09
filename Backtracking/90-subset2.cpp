#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 
class Solution {
public:

    void bagu(vector<int>&nums,vector<int>&ans,vector<vector<int>> &allSubsets,int i){
        if(i==nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        bagu(nums,ans,allSubsets,i+1);
        ans.pop_back();

        int index = i+1;
        while(index<nums.size() && nums[index] == nums[index-1]){
            index++;
        }
        bagu(nums,ans,allSubsets,index);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans ; 
        vector<vector<int>> allSubsets; 
        bagu(nums,ans,allSubsets,0);
        return allSubsets;
    }
};