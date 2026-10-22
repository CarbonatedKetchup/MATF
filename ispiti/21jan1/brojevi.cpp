#include <iostream>
#include <vector>

using namespace std;

void ispisi(vector<int> &v, int i){
  
  if(i == v.size()){
    for(int x: v){
      cout << x;
    }
    cout << '\n';
    return;
  }
  
  for(int j = (i == 0); j < 4; j++){
    v[i] = j;
    if(i > 0 && v[i] %2 == 1 && v[i-1] % 2 == 1){
      continue;
    }
    ispisi(v, i+1);
  }
}

int main() {

  int n;
  cin >> n;
  
  vector<int> v(n);
  ispisi(v, 0);

  return 0;
}
