#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {

  int n, k;
  cin >> n >> k;
  
  int x;
  string s;
  
  map<string, int> korisnici;
  map<int, int> br_korisnika;
  br_korisnika[0] = k;
  
  for(int i = 0; i < n; i++){
    cin >> s >> x;
    
    if(s == "upit"){
      cout << br_korisnika[x] << '\n';
    }else{
      br_korisnika[korisnici[s]]--;
      korisnici[s] += x;
      br_korisnika[korisnici[s]]++;
    }
  }

  return 0;
}
