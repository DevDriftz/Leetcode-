#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 


int sum(vector<int>&nums,int isum,int index){
  if(index == nums.size()){
    return isum;
  }

  sum(nums,isum+nums[index],index+1);
  
}


void printNumber(int n){
    if(n==0){
        return ; 
    }
    cout<<n;
    printNumber(n-1);
}



string Reverse(string name,int st, int end){

    if(st>=end){
        return name;
    }
    swap(name[st],name[end]);

    return Reverse(name,st+1,end-1);

}

int main(){
    vector<int> nums = {1,2,3,4,5,90,67,9};
//   printNumber(5);
    string s = "tahskA";
    cout<< Reverse(s,0,s.size()-1);
}
