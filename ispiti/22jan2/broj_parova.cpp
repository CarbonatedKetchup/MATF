#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, t;
  cin >> n >> t;
  
  map<int, int> br_pojavljivanja;
  
  string s;
  int x;
  int br_nacina = 0;
  
  for(int i = 0; i < n; i++){
    cin >> s;
    if(s == "upit"){
      cout << br_nacina << '\n';
    }else if(s == "pisi"){
      cin >> x;
      int komplement = t - x;
      br_nacina += br_pojavljivanja[komplement];
      br_pojavljivanja[x]++;
    }else if(s == "brisi"){
      cin >> x;
      int komplement = t -x;
      br_nacina -= br_pojavljivanja[komplement];
      br_pojavljivanja[x]--;
    }
  }

  return 0;
}
