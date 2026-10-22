#include <iostream>
#include <vector>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  
  vector<int> placevi(n);
    
  for(int i = 0; i < n; i++){
    cin >> placevi[i];
  }
  
  vector<int> max_potrosnja(n);
  max_potrosnja[0] v[0];
  max_potrosnja[1] = 2 * max(v[0], v[1]);
  for(int i = 2; i < n; i++){
    max_potrosnja[i] = max( (v[i] + max_potrosnja[i-1]), (2*max(v[i], v[i-1]) + max_potrosnja[i-2]) );
  }
  
  cout << max_potrosnja[n-1] << endl;

  return 0;
}
