#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {

  int n, d;
  cin >> n >> d;

  vector<int> v(n);
  map<int, bool> postoji;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    postoji[v[i]] = true;
  }
  
  //cout << "proslo";
  
  /*
  int max_duzina = 0;
  int curr_duzina = 0;
  
  sort(v.begin(), v.end());
  
  for(int i = 0; i < n-1; i++){
    if(v[i+1] - v[i] == d){
      curr_duzina++;
      cout << curr_duzina;
      if(curr_duzina > max_duzina){
        max_duzina = curr_duzina;
      }
    }else{
      curr_duzina = 0;
    }
  }
  
*/

  sort(v.begin(), v.end());
  map<int, int> duzinaDo;
  int max_duzina = 1;
  for(int i = 0; i < n; i++){
    if(duzinaDo.find(v[i] - d) != duzinaDo.end()) { //ako prethodnik postoji u duzinaDo
      duzinaDo[v[i]] = duzinaDo[v[i] - d] + 1;
      max_duzina = max(max_duzina, duzinaDo[v[i]]);
    }else{  //ako nema prethodnika
      duzinaDo[v[i]] = 1;
    }
  }
  
  cout << max_duzina << '\n';

  return 0;
}
