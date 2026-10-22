#import <iostream>
#import<vector>
#import <string>

using namespace std;

char suprotan_smer(char c){
  switch(c) {
    case 'L': return 'R';
    case 'R': return 'L';
    case 'U': return 'D';
    case 'D': return 'U';
  }
  return 0;
}

int main() {

  string s;
  cin >> s;
  
  string stek;
  
  for(char c : s){
    if(!stek.empty() && stek.back() == suprotan_smer(c)){
      stek.pop_back();
    }else{
      stek.push_back(c);
    }
  }
  
  cout << stek << '\n';

  return 0;
}
