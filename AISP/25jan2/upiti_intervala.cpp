#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  //ios_base::sync_with_stdio(false);
  //cin.tie(0);

  int n;
  cin >> n;
  
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  
  int k;
  cin >> k;
  
  int x, y;
  while(k--){
    cin >> x >> y;
    
    /*
    if(v[n-1] < x){
      cout << "NEMA" << '\n';
    }
    int l = 0, d = n-1;
    while(l < d && l < n && d < n){
      if(v[l] < x){
        l++;
      }
      if(v[d] > y){
        d--;
      }
    }
    if(l != d){
      cout << v[l] << ' ' << v[d] << '\n';
    }else{
      cout << "NEMA" << '\n';
    }
    */
    
    auto it_min = lower_bound(v.begin(), v.end(), x);
    auto it_max = upper_bound(v.begin(), v.end(), y) - 1;
    
    if(it_max < it_min){
      cout << "NEMA" << endl;
    }else{
      cout << *it_min << ' ' << *it_max << endl;
    }
    
  }

  return 0;
}
