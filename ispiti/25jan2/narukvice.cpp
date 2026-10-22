#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

  int n, k;
  string s;
  
  cin >> n >> k >> s;
  
  char mod;
  for(int i = 0; i < n; i++){
    cin >> mod;
    string tmp;
    
    if(mod == 'k'){
      tmp = s;
      s.append(tmp);
    }else if(mod == 'o'){
      tmp = s;
      tmp = string(tmp.rbegin(), tmp.rend()); //reversed string
      s.append(tmp);
    }
  }
  
  vector<char> kopija;
  for(char c: s){
    kopija.push_back(c);
  }
  
  for (char c : kopija){
    cout << c << ' ';
  }
  cout << endl;
  
  cout << kopija[k] << '\n';

  return 0;
}
