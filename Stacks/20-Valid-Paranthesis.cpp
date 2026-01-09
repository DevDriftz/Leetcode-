//using vectors not stacks...

#include<iostream>
#include<vector>
using namespace std;


bool isValid(string str){
  vector<char>vec;
  for(int i=0; i<str.length();i++){
    if(str[i] == '(' || str[i] == '{' || str[i] == '['){
        vec.push_back(str[i]);
    }else{
        if(vec.size()==0){
            return false;
        }
        if(str[i]=='}' and vec.back()=='{' || str[i]==')' and vec.back()=='(' || str[i]==']' and vec.back()=='[' ){
            vec.pop_back();

        }else{
            return false;
        }
    }
  }
  return vec.size()==0;
}

int main(){
  string str;
  cin>>str;
  cout<<isValid(str);
  return 0;
}
