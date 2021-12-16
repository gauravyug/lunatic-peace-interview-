#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
Implement regular expression 
. -> Match any single character
* -> Zero or more characters
Regex: *at 
Input: Cat -> True
Cats -> False
Str : abcat
pat : *at

      abc*
      abcdef
*/
         

int add_numbers(int a, int b) {
    return a+b;
}
 bool regexmatch(string str, string pattern, int m , int n) {
     if (m == 0 || n == 0) {
         if (str[m] == pattern[n] || pattern[m] == '*'  || pattern[n] == '.')
         return true;
        return false;
     }
    if (str[m] == pattern[n] || pattern[m] == '.') 
        return regexmatch(str, pattern, m-1, n-1);
    if (pattern[n]  == '*' && pattern[n-1] != str[m]) {
        return regexmatch(str, pattern, m-1, n);
    }
   
        return regexmatch(str, pattern, m-1, n-1);
   
 }
 bool regesmatch(string str, string pattern) {
     if (str == pattern) {
         return true;
     }
     if (pattern == "") {
         return false;
     }
     bool match = str.size() > 0 && (pattern[0] == str[0] || pattern[0] == '.');
     if (match) {
         if (str.size() >=2 && pattern[1] == '*') 
            return  regesmatch(str, pattern.substr(2)); 
        return regesmatch(str.substr(1),pattern.substr(1) );
     }
     //return regesmatch(str.substr(1), pattern.substr(1));
     
    if (pattern.size() == 1 || pattern[1] != '*') {
        return false;
    }
    return regesmatch(str, pattern.substr(2)); 
     
 }
bool isMatch(string s, string p) {
    
        //RECURSIVE (Exponential) 
        // CAN BE IMPROVED BY MEMO BUT I WILL USE TABULATION AS ITS QUITE EASY TO GO FOR MEMO BUT ITS NOT SO EASY DOING ITERATIVELY!!
        
        if(p.size()==0){
            if(s.size()==0){
                return true;
            }
            return false;
        }
        
        if(p.size()>1 && p[1]=='*'){
            if(isMatch(s,p.substr(2))){
                return true;
            }
            if((p[0]=='.' || s[0]==p[0]) && s.size()>0){
                return isMatch(s.substr(1),p);
            } 
            return false;
        }
        else{
            if((p[0]=='.' || p[0]==s[0]) && s.size()>0){
                return isMatch(s.substr(1),p.substr(1));
            }
            return false;
        }
        
    }
int main() {
    //bool res = regexmatch("cat", "*atp", 2, 2);
   
    string str2 = ".*at";
    string str1 = "cat";
    bool res = regesmatch(str1 , str2);
    cout << str1  << " " << str2  << " ";
     if (res) 
        cout <<"Matched" << endl;  
    else 
        cout << "Not Matched" << endl;
         return 0;
}