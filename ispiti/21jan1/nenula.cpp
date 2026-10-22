#include <iostream>
#include <map>

using namespace std;

int main() {

  int64_t n;
  cin >> n;
  
  map<int,int> bp;
  int64_t x;
  int64_t broj_parova_nula = 0;
  for(int64_t i = 0; i < n; i++){
    cin >> x;
    broj_parova_nula += bp[-x];
    bp[x]++;
  }
  int64_t ukupno_parova = (int64_t)(n * (n-1)) / 2;
  cout << ukupno_parova - broj_parova_nula << '\n';
  
  

  return 0;
}
