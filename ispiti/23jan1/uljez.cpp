#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(vector<char> &s, int k, int pos, int ones){
  int n = s.size();
  
  if(ones > k){
    return; //ako smo popunili sve . a imamo vise jedinica nego dozvoljeno
  }
  if(ones + (n - pos) < k){
    return; //ako nemamo dovoljno jedinica da popunimo sve
  }
  
  if(pos == n){
    if(ones == k){
      for(char c : s){
        cout << c;
      }
      cout << '\n';
    }
    return;
  }
  
  if(s[pos] != '.'){
    solve(s, k, pos+1, ones + (s[pos] == '1'));
  }else{
    for(char c : {'1', '2', '3'}){
      s[pos] = c;
      solve(s, k, pos+1, ones + (c == '1'));
    }
    s[pos] = '.';
  }
}

int main() {

  int k;
  cin >> k;
  
  string sifra;
  cin >> sifra;
  int n = sifra.length();
  
  //cout << sifra << ' ' << n;
  
  vector<char> res(n);
  for(int i = 0; i < n; i++){
    res[i] = sifra[i];
  }
  
  solve(res, k, 0, 0);

  return 0;
}
