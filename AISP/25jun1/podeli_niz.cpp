#include <iostream>
#include <vector>

using namespace std;

int part(vector<int> &v, const int i){
  const int n = v.size();
  if(i == n){
    return 1;
  }
  
  int count = 0;
  for(int j = i; j < n; j++){
    if(v[i] %2 == v[j] % 2){
      count += part(v, j+1);
    }
  }
  return count;
}

int main(){

  int n;
  cin >> n;
  
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  cout << part(v, 0) << endl;

  return 0;
}
