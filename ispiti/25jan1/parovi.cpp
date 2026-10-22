#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  int n;
  cin >> n;
  
  int br_neg = 0;
  
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
    if(v[i] < 0){
      br_neg++;
    }
  }
  
  sort(v.begin(), v.end());
  
  int br = 0;
  
  /* kvadratna slozenost:
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(v[i] + v[j] > 0 && (v[i]+v[j]) % 2 == 0){
        br++;
      }
    }
  }
  */
  
  /* pogresno resenje
  int i = 0, j = 1;
  while(i < n && j < n){
    if(j == n-1){
      i++;
      j = i+1;
    }
    if(v[i] + v[j] > 0 && ((v[i] < 0 && v[j] > 0) || (v[i] > 0 && v[j] < 0))){
      br++;
    }
    j++;
    if(v[i] + v[j] <= 0 && ((v[i] > 0 && v[j] > 0) || (v[i] < 0 && v[j] < 0))){
      j++;
    }
  }
  */
  
  int i = 0, j = n-1;
  while(i < j){
    if(v[i] + v[j] > 0){
      br += br_neg;
      j--;
    }else{
      br_neg--;
      i++;
    }
  }
  
  cout << br;

  return 0;
}
