#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int64_t> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  map<int64_t, int> br_pojavljivanja;
  for(int i = 0; i < n; i++){
    br_pojavljivanja[v[i]]++;
  }
  
  int brojac = 0;
  for(auto pair : br_pojavljivanja){
    if(pair.second % 2 == 0){
      brojac++;
    }
  }
  
  cout << brojac << '\n';

  return 0;
}
