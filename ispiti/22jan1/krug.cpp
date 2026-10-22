#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int64_t n, r, d;
  cin >> n >> r >> d;
  
  int64_t x;
  for(int64_t i = 0; i < n; i++){
    cin >> x;
    
    if(abs(x) > r){
      cout << 0 << '\n';
    }else{
      cout << (r - abs(x)) / d + 1;
    }
  }

  return 0;
}
