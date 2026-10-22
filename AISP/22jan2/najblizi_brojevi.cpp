#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

  int64_t n, k, x;
  cin >> n >> k >> x;
  
  vector<int64_t> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  sort(v.begin(), v.end());
  //auto it = upper_bound(v.begin(), v.end(), x) - v.begin();
  //vector<int64_t> rez;
  
  //int64_t min_razlika = 0;
  /*
  for(int i = 0; i < n; i++){
    if(v[i] < v[it]){
      rez.push_back(v[i]);
    }
  }
  */
  
  int64_t l = 0, r = n-1;
  while(r-l >= k){
    if(abs(v[l] - x) <= abs(v[r] - x)){
      r--;
    }else{
      l++;
    }
  }
  
  
  for(int64_t i = l; i < l+k; i++){
    cout << v[i] << ' ';
  }
  cout << '\n';

  return 0;
}
