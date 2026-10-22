#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

  string s;
  cin >> s;
  
  /*
  int n = s.length();
  vector<char> tmp(n);
  int iter = 0;
  for(char c : s){
    tmp[iter] = c;
    iter++;
  }
  
  vector<char> res;
  int i = 0, j = 0;
  while(i < n && j < n){
    if(tmp[i] == tmp[j]){
      i--;
    }else {
      res.push_back(tmp[i]);
      i++;
      j++;
    }
  }
  */
  
  string str;
  for(char c : s){
    if(str.empty() || str.back() != c){
      str.push_back(c);
    }else{
      str.pop_back();
    }
  }
  
  cout << str << '\n';

  return 0;
}
