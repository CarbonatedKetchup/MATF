#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n, k1, k2;
  cin >> n >> k1 >> k2;
  
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  vector<int> digit;
  vector<int> count;
  
  for(int i = 0; i < n; i++){
    if(digit.empty()){
      digit.push_back(v[i]);
      count.push_back(1);
    }else if(v[i] != digit.back()){ //!digit.empty()
      if((digit.back() == 0 && count.back() >= k1) || 
         (digit.back() == 1 && count.back() >= k2)){
            digit.pop_back();
            count.pop_back();
            if(!digit.empty()){
              count.back()++;
            }
      }else{
        digit.push_back(v[i]);
        count.push_back(1);
      }
    }else{  //!digit.empty() && v[i] == digit.back()
      count.back()++;
    }
  }
  
  //moramo posle petlje da proverimo jos jednom da nismo presli limit
  if((digit.back() == 0 && count.back() >= k1) || 
      (digit.back() == 1 && count.back() >= k2)){
          digit.pop_back();
          count.pop_back();
  }
  
  for(int i = 0; i < digit.size(); i++){
    for(int j = 0; j < count[i]; j++){
      cout << digit[i] << " ";
    }
  }
  cout << endl;

  return 0;
}
