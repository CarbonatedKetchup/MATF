#include <iostream>
#include <vector>

using namespace std;

int main(){

  int64_t n;
  cin >> n;
  
  int k;
  cin >> k;
  
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  int l = 0;
  int r;
  int broj_nula = 0;
  int maksimum = -1;
  for(r = 0; r < n; r++){
    if(v[r] == 0){
      broj_nula++;
    }
    while(broj_nula > k){
      if(v[l] == 0){
        broj_nula--;
      }
      l++;
    }
    maksimum = max(maksimum, r-l+1);
  }
  
  cout << maksimum;
  
  return 0;
}
