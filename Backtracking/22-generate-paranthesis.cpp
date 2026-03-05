#include<iostream>
#include<vector>
using namespace std; 

class Solution{
public:

  void solve(vector<string>&ans, int n, int open, int close, string s){
    if(s.length() == 2*n){
      ans.push_back(s);
      return ;
    }
    if(open<n){
      solve(ans,n,open+1,close,s+"(");
    }

    if(close<open){
      solve(ans,n,open,close+1,s+")");
    }
  
    
  }
  vector<string> generateParenthesis(int n){
    vector<string>ans;
    solve(ans,n,0,0,"");
    return ans;
  }
};

int main(){
  Solution s;
  int input; cin>>input;
  vector<string> res = s.generateParenthesis(input);
  for(int i=0; i<res.size(); i++){
    cout<<i<<". "<<res[i] << endl;
  }
  return 0;
}
