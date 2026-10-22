#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int64_t n;
  cin >> n;
  
  vector<int64_t> niz(n);
  for(int64_t i = 0; i < n; i++){
    cin >> niz[i];
  }
  
  sort(niz.begin(), niz.end());
 //ovo prolazi
  
  int64_t q;
  cin >> q;
  
  /*
  int64_t x, rez = 0;
  vector<int64_t> upiti(q);
  for(int64_t i = 0; i < q; i++){
    cin >> x;
    upiti[i] = x;
    int64_t j = 0;
    while(niz[j] <= x){
      rez += niz[j];
      j++;
    }
    cout << rez << '\n';
    rez = 0;
  }
  */
  //ovo resenje ne valja zbog slozenosti, parcijalnim sumama mozemo da ga popravimo
  
  vector<int64_t> partial(n+1, 0);
  partial_sum(niz.begin(), niz.end(), partial.begin()+1);
  
  for(int i = 0; i < q; i++){
    int64_t x;
    cin >> x;
    int pos = upper_bound(niz.begin(), niz.end(), x) - niz.begin();
    cout << partial[pos] << '\n';
  }

  return 0;
}
