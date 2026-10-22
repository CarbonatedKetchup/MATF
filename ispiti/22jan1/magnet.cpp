#include <iostream>
#include <vector>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int64_t n, k;
  cin >> n >> k;
  
  vector<int64_t> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }

  int64_t predjen_put = 0;
  int64_t broj_kuglica = 0;
  for(int i = 0; i < k; i++){
    broj_kuglica += v[i];
    predjen_put += (i+1) * v[i];
  }
  
  int64_t max_put = predjen_put;
  for(int i = k; i < n; i++){
    predjen_put -= broj_kuglica;
    predjen_put += v[i] * k;
    max_put = max(max_put, predjen_put);
    
    broj_kuglica -= v[i-1];
    broj_kuglica += v[i];
  }
  
  cout << max_put << '\n';

  return 0;
}
