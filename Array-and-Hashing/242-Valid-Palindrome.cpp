#include<iostream>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        bool anagram = false;
        (s.begin(),s.end());
        (s.begin(),s.end());
        if (s.size() == t.size()){
            for(int i=0;i<s.size();i++){
                if(s[i]==t[i]){
                    anagram = true;
                }
                else{
                    anagram = false;
                    return anagram;
                }
            }
        }
        return anagram;
    }
};