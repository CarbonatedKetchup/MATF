#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int64_t n;
  cin >> n;
  
  vector<int> a(n);
  vector<int> m(n);
  vector<int> b(n);
  
  vector<int> polozaji_posle_mesanja(n);
  vector<int> b_posle_mesanja(n);
  
  int x, curr_index;
  
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  for(int i = 0; i < n; i++){
    cin >> m[i];
    x = m[i];
    auto it = find(a.begin(), a.end(), x);
    curr_index = distance(a.begin(), it);
    polozaji_posle_mesanja[i] = curr_index;
  }

  for(int i = 0; i < n; i++){
    cin >> b[i];
  }

  cout << "provera----------------------" << '\n';
  for(int i = 0; i < n; i++){
    cout << polozaji_posle_mesanja[i];
  }
  cout << "kraj provere-----------------" << '\n';
  
  int target_index;
  for(int i = 0; i < n; i++){
    target_index = polozaji_posle_mesanja[i];
    b_posle_mesanja[i] = b[target_index];
  }

  for(int i = 0; i < n; i++){
    cout << b_posle_mesanja[i] << ' ';
  }
  cout << '\n';
  
  return 0;
}
