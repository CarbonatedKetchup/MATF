#include <iostream>
#include <vector>

using namespace std;


int mod_inverz(vector<int> &v){
  int n = v.size();
  
  int i = 0, j = 1;
  int br = 0;
  while(i < j){
    if(v[i] < v[j]){
      br++;
    }
  }
  
  return br;
}
  //nah fuck this ovo nije linearno, onaj kvad dole je good enough


int main(){

/*
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  int k;
  cin >> k;
  */
  
  /*    KVADRATNA SLOZENOST:
  int br = 0;
  for(int i = 0; i < n-1; i++){
    for(int j = 1; j < n; j++){
      if(v[i] % k > v[j] % k){
        br++;
      }
    }
  }
  */
  
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  int k;
  cin >> k;
  
  for(int i = 0; i < n; i++){
    v[i] %= k;
  }
  
  int br = mod_inverz(v);
  
  cout << br << endl;

  return 0;
}
