#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v, int i){
  if(i == v.size()){
    for(int x : v){
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }
  
  v[i] = v[i-1];
  print(v, i+1);
  
  v[i] = v[i-1] + 1;
  print(v, i+1);
}

void stepenasti(n){
  vector<int> v(n);
  v[0] = 1;
  print(v, i+1);
}

int main() {

  int n;
  cin >> n;
  
  stepenasti(n);

  return 0;
}
