#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){

  int n;
  cin >> n;
  
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  int max_duzina = 0;
  
  /*  KVADRATNA:
  for(int i = 0; i < n-1; i++){
    for(int j = i+1; j < n; j++){
      if(abs(v[i]) == abs(v[j])){
        max_duzina = max(max_duzina, j-i+1);
      }
    }
  }
  */
  
  //br koji trazimo : njegov index
  unordered_map<int, int> seen;
  
  for(int i = 0; i < n; i++){
    if(seen.find(-v[i]) != seen.end()){ //ako -v[i] postoji
      max_duzina = max(max_duzina, i - seen[-v[i]] + 1)
    }
    if(seen.find(v[i]) == seen.end()){
      seen[v[i]] = i;
    }
  }
  
  cout << max_duzina << '\n';

  return 0;
}
