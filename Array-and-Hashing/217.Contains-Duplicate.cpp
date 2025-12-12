#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std ; 

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s ; 

        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) != s.end()){
                cout<<"true";
                return true; 
            }
            s.insert(nums[i]);

           
        }
        cout<<"false";
        return false;
        
    }
};

int main(){
    vector<int> nums = {1,2,3,4,9};
    Solution s1;
    s1.hasDuplicate(nums);
}
