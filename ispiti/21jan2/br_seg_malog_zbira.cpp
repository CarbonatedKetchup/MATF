#include <iostream>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  
  int t;
  cin >> t;
  
  int zbir = 0;
  int br_seg = 0;
  int l = 0, d;
  
  for(d = 0; d < n; d++){
    zbir += v[d];
    
    while(l <= d && zbir >= t){
      zbir -= v[l];
      l++;
    }
    br_seg += (d - l + 1);
  }
  
  cout << br_seg << endl;

  return 0;
}
