#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n, t;
  cin >> n >> t;
  
  vector<int>v (n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  int l=0, d=0;
  int min_k = 0;
  int zbir = v[0];
  while(d < n){
    if(zbir < t){
      d++;
      zbir += v[d];
      min_k = max(min_k, d-l+1);
    }else{
      zbir -= v[l];
      l++;
    }
  }
  
  if(min_k == n+1){
    cout << 0 << '\n';
  }else{
    cout << min_k << '\n';
  }

  return 0;
}
