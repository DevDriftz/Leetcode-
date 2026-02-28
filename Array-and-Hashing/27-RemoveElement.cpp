#include<iostream>
#include<vector>
using namespace std; 

class Solution{
public: 

  int removeElement(vector<int> &nums , int val){
    int count=0 ; int index =0;
    for(auto x : nums){
      if(val != x){
        nums[index++] = x;

        count++;
      }
    }

    return count;
  }


};


int main (int argc, char *argv[]) {
  Solution s;
  int val = 2;
 vector<int>nums = {0,1,2,2,3,0,4,2};
  int k = s.removeElement(nums,val);
  for(int i=0; i<k; i++){
    cout<<nums[i]<<" ";
  }
  return 0;
}
